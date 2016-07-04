class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // Init: first row / column anything after 1 will get zero. Before get 1.
        // Update: if 1, then value is 0.
        vector<vector<int>>& a = obstacleGrid;
        int m = a.size();
        if(m == 0) return 0;
        int n = a[0].size();
        if(n == 0) return 0;
        vector<vector<int>> ways(m, vector<int>(n,0));
        int val = 1;
        for(int j=0; j<n; j++)
        {
            if(a[0][j] == 1) val = 0;
            ways[0][j] = val;
        }
        val = 1;
        for(int i=0; i<m; i++)
        {
            if(a[i][0] == 1) val = 0;
            ways[i][0] = val;
        }
        for(int i=1; i<m; i++)
            for(int j=1; j<n; j++)
            {
                if(a[i][j] == 1)
                    ways[i][j] = 0;
                else
                    ways[i][j] = ways[i-1][j] + ways[i][j-1];
            }
        return ways[m-1][n-1];
    }
};