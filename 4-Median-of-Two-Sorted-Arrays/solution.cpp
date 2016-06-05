class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Naive solution is to merge two lists in O(m+n) time, then get median in O(1) time. Space also O(m+n).
        // So expected complexity likely log(m+n), or [log(m+n)]^2.
        // Note that median is easier than finding value, or get average for sorted list. O(1) vs O(logn), O(n).
        // Direct indexing, counting number of entries to the left & right, without search would be most efficient.
        // First step / guess would be take medians of both lists and compare. Suppose lists a & b, lengths m & n.
        // Median definition: For list a of length m, median would satisfy: 
        // floor(m/2) entries <= median, and floor(m/2) entries >= median. Necessary and sufficient. Good for both odd & even m.
        // Suppose lists a & b, lengths (2m+1) and (2n+1). So total length even, median is the average of two numbers.
        // Indices starting from 1. If a[m+1] > b[n+1], then:
        // Number of entries <= a[m+1] is at least m + (n+1), so no need to search a[m+2 ... end].
        // Similarly, entries >= b[n+1] is at least (m+1) + n, so no need to search b[1: n].
        // So search space is reduced by half. Good progress!
        // Next, try reduce further we want to move to a[m/2] and b[n+n/2]. 
        // If compare the two, we still get a[m/2] > b[n+n/2], then: no conclusion, need to move a & b indices by same distance to keep median property. So we move by min(m,n)/2.
        // Special case: If b[2n+1] < a[1], then easy. If b[2n+1] < a[m-n], then also get answer.
        // We compare b[n+1+d] and a[m+1-d], initially d = min(m,n). If b[n+1+d] smaller, then there are at least (n+1+d+m-d) = (m+n+1) entries smaller than a[m+1-d], so no need to search a[1... m-d]. Similarly, at least (2n+1 - (n+1+d) + (2m+1) - (m+1-d) +1 = n - d + m + d + 1 = m+n+1 entries larger than b[n+1+d], so no need to search b[n+1+d ... end]. This also reduces range. 
        // At this point, the search range of a and b are equal to min(m,n). Then reduce d by half, and do binary search, compare and reduce search space by half each time, until the search space is only 1. 
        // Actually, at most 4 numbers, two from a and two from b. Then post-process the 4 numbers to give final answer.
        // Just use m & n, and m/2, n/2, assume both odd, then revise for 3 other cases.
        int m = nums1.size();
        int n = nums2.size();
        vector<int>& a = nums1;
        vector<int>& b = nums2;
        
        int la = 0, ha = m-1; // high / low range for search space in a[].
        int lb = 0, hb = n-1;
        int pa = ha/2; // good if m is odd, e.g. 101, then get 50.
        int pb = hb/2;
        
        if(a[pa] == b[pb]) return a[pa]; // median of two lists same, return it.
        
        int d = min(m/2, n/2); // good for odd m & n, e.g. 101 then 50.
        if(a[pa] > b[pb])
        {
            ha = pa, lb = pb;
            if(m >= n)
            {
                if(a[ha-d] >= b[n-1]) // then no need to search a[1:ha-d-1]
                    la = ha-d;
                else
                    
            }
        }
            
        else
            la = pa, hb = pb;
        
        
        // 
        
        return 0;
    }
};