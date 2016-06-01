class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // kth row has k+1 entries. Easy to miss is 0th row has 1 entry (1), so 0 is also valid input.
        if (rowIndex < 0) return vector<int>();//invalid input
        vector<vector<int> > a(2,vector<int>(rowIndex+1,1)); // initialize all entries to 1.
        // we use ping-pong buffer to avoid excessive copying
        // For k == 1, we already have result in a[0]: {1, 1}. Now we calculate k == 2 result in a[1].
        // The returned vector is a[(k-1)&1]. If k odd, then a[0]. If k even, then a[1].
        // To calculate result for odd k, we derive a[0] from a[1]. To calculate for even k, we derive a[1] from a[0].
        // So in = k&1, out = (k-1)&1.
        for(int k = 2; k <= rowIndex; k++)// k is counter for 2 : rowIndex
        {
            int in = k&1;
            int out = (k+1)&1;
            // Now we derive a[out] from a[in]. The number of valid entries in a[in] == k. The number of entries to derive in a[out] is [1 ... k-1]. Entry k is always 1. a[out] always has k+1 valid entries.
            for(int i=1; i < k; i++)
                a[out][i] = a[in][i] + a[in][i-1];
        }
        return a[(rowIndex+1)&1];
    }
};