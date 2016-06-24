class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> r(n, vector<int>(n));
        // i is column counter, j is row counter. Start with i=j=0, increment i until i < n.
        // End condition is we wrote n^2 entries. large number, long long.
        // Maintain i_l lower limit, i_h higher limit, i_d direction. Four iterations in each loop.
        // Iter 1: after complete, j_l increment. Iter 2: after complete, i_h decrement.
        // Iter 3: after complete, j_h decrement. Iter 4: after complete, i_l increment.
        // Input assumes n^2 can be held by int.
        int c = 1;
        int i_l = 0, i_h = n-1, j_l = 0, j_h = n-1;
        while(c <= n*n)
        {
            for(int i=i_l; i<=i_h; i++)
                r[j_l][i] = c++;
            j_l++;
            for(int j=j_l; j<=j_h; j++)
                r[j][i_h] = c++;
            i_h--;
            for(int i=i_h; i>=i_l; i--)
                r[j_h][i] = c++;
            j_h--;
            for(int j=j_h; j>=j_l; j--)
                r[j][i_l] = c++;
            i_l++;
        }
        return r;
    }
};