class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Assume ascending.
        if(m<0 || n<0) return; // error.
        // Goal is to be efficient. Ideally move each element in place.
        // Entries in nums1 are only moved to the right. Entries in nums2 are directly copied to their final places in nums1.
        nums1.resize(m+n); // allow direct indexing to places beyond m.
        // Work backwards
        int i, j, k;
        k = m+n-1; // k points to last position in output
        for(i = m-1, j = n-1; i >= 0 && j >= 0;)
        {
            if(nums1[i] > nums2[j])
            {
                nums1[k] = nums1[i];
                k--;
                i--;
                continue;
            }
            else
            {
                nums1[k] = nums2[j];
                k--;
                j--;
                continue;
            }
        }
        while(j>=0) // nums2[] has values smaller than original nums1[0] (now nums1[j+1]), copy them to nums1[].
        {
            nums1[j] = nums2[j];
            j--;
        }
    }
};