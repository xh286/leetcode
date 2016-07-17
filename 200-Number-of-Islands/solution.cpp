class Solution {
private:
    void visitIsland(vector<vector<char>>& to_visit, int i, int j)//visit (set to zero) all '1' neighbors of (i,j)
    {
        to_visit[i][j] = '0';
        int m = to_visit.size();
        int n = to_visit[0].size();
        if(i-1>=0 && to_visit[i-1][j] == '1') visitIsland(to_visit,i-1,j);
        if(j-1>=0 && to_visit[i][j-1] == '1') visitIsland(to_visit,i,j-1);
        if(i+1<m && to_visit[i+1][j] == '1') visitIsland(to_visit,i+1,j);
        if(j+1<n && to_visit[i][j+1] == '1') visitIsland(to_visit,i,j+1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<char>> to_visit = grid;
        int m = to_visit.size();
        if(m==0) return 0;
        int n = to_visit[0].size();
        if(n==0) return 0;
        int num_islands = 0;
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(to_visit[i][j] == '1')
                {
                    visitIsland(to_visit,i,j);
                    num_islands++;
                }
        return num_islands;
    }
};