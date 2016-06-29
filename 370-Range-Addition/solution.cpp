class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        int n = length;
        vector<int> r(n,0);
        int m = updates.size();
        for(int i=0; i<m; i++)
        {
            int start = min(n-1,max(0,updates[i][0]));
            int end = min(n-1,max(0,updates[i][1]));
            int val = updates[i][2];
            r[start] += val;
            if(end<n-1)
                r[end+1] -= val;
        }
        // convert r to cumsum.
        for(int i=1; i<n; i++)
        {
            r[i] += r[i-1];
        }
        return r;
    }
};