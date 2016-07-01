class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if(m>n) return findMedianSortedArrays(nums2,nums1); // require m<=n.
        vector<int>& a = nums1;
        vector<int>& b = nums2;
        // Partition into two sets: Left: a[0...i-1], b[0...j-1] and Right: a[i...m-1], b[j...n-1].
        // If m+n odd, then Left can be 1 longer. Otherwise, Left and Right same length.
        // Make sure all elements in Left is <= those in Right. So a[i-1] <= b[j] and b[j-1] <= a[i].
        // Given i, j = (m+n+1)/2-i.
        // If condition satisfied, then i found. If odd, then max(Left) is median. Otherwise, (max(Left)+min(Right))/2
        // If not satisfied. If a[i-1] > b[j], then increasing i will decrease j, won't satisfy, so high = i-1.
        // If b[j-1] > a[i], then low = i+1. End of loop when low>high.
        int low = 0;
        int high = m-1;
        while(true)
        {
            int i = low+(high-low)/2;
            int j = (m+n+1)/2 -i;
            if(i!=0 && j!=n && a[i-1] > b[j]) high = i-1;
            else if(j!=0 && i != m && b[j-1] > a[i]) low = i+1;
            else // return from here
            {
                int left_max = INT_MIN;
                if(i!=0) left_max = max(left_max,a[i-1]);
                if(j!=0) left_max = max(left_max,b[j-1]);
                if((m+n)%2 == 1)
                {
                    return left_max;
                }
                int right_min = INT_MAX;
                if(i!=m) right_min = min(right_min, a[i]);
                if(j!=n) right_min = min(right_min, b[j]);
                return ((double)(left_max+right_min)/2.0);
            }
        }
    }
};