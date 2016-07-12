class Solution {
private:
    int findOne(vector<int>& a, int v) // any index i s.t. a[i]==v. If no match, return -1.
    {
        int low = 0, high = a.size()-1;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(v < a[mid]) high = mid - 1;
            else if(v > a[mid]) low = mid + 1;
            else return mid;
        }
        return -1;
    }
    int findFirst(vector<int>& a, int v)
    {
        int low = 0;
        int high = findOne(a, v);
        if(high<0) return -1;
        if(a[low]==v) return 0;
        // Now a[low]<v, a[high]=v. Maintain this invariant, and reduce range until low+1==high.
        
        while(high-low>1)
        {
            int mid = low + (high-low)/2;
            if(a[mid]<v) low = mid;
            else high = mid; // v == a[mid]
        }
        return high;
    }
    int findLast(vector<int>& a, int v)
    {
        int low = findOne(a,v);
        int high = a.size()-1;
        if(low<0) return -1;
        if(a[high]==v) return high;
        // Now a[low]=v, a[high]>v. Maintain this invariant, reduce range until low+1==high.
        while(high-low>1)
        {
            int mid = low + (high-low)/2;
            if(a[mid] == v) low = mid;
            else high = mid;
        }
        return low;
    }
    
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // Implements lower_bound, and upper_bound. Return [lower_bound, upper_bound-1].
        vector<int> ret;
        ret.push_back(findFirst(nums,target));
        ret.push_back(findLast(nums,target));
        return ret;
    }
};