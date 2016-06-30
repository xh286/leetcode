class Solution {
private:
    vector<vector<int>> Dist2OneBuilding(vector<vector<int>>& grid, int ii, int jj)
    {
        int m = grid.size();
        int n = grid[0].size();
        // Return distances to given building at (i,j).
        vector<vector<int>> dist(m,vector<int>(n,-1));
        queue<pair<int,int>> bfs_queue;
        // assert(grid[ii][jj] == 1);
        bfs_queue.insert({ii,jj});
        dist[ii][jj]=0;
        while(!bfs_queue.empty())
        {
            auto loc = bfs_queue.front();
            bfs_queue.pop();
            // check all 4 directions
            int i = loc.first;
            int j = loc.second; // i, j must be valid
            if(i-1>=0 && grid[i-1][j] == 0 && dist[i-1][j] == -1) //unvisited empty space
            {
                bfs_queue.push({i-1,j});
                dist[i-1][j] = dist[i][j] + 1;
            }
            if(i+1<m && grid[i+1][j] == 0 && dist[i+1][j] == -1) //unvisited empty space
            {
                bfs_queue.push({i+1,j});
                dist[i+1][j] = dist[i][j] + 1;
            }
            if(j-1>=0 && grid[i][j-1] == 0 && dist[i][j-1] == -1) //unvisited empty space
            {
                bfs_queue.push({i,j-1});
                dist[i][j-1] = dist[i][j] + 1;
            }
            if(j+1<n && grid[i][j+1] == 0 && dist[i][j+1] == -1) //unvisited empty space
            {
                bfs_queue.push({i,j+1});
                dist[i][j+1] = dist[i][j] + 1;
            }
        }
        return dist;
    }
    void distSum(vector<vector<int>>& dist_sum, vector<vector<int>>& new_dist) // if either old/new is -1, result is -1. Otherwise, add up.
    {
        if(dist_sum.size() == 0) // first building
        {
            dist_sum = new_dist; // copy assignment
            return;
        }
        // dist_sum and new_dist not empty, and same sizes
        int m = new_dist.size();
        int n = new_dist[0].size();
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
            {
                if(dist_sum[i][j] == -1 || new_dist[i][j] == -1)
                    dist_sum[i][j] = -1;
                else
                    dist_sum[i][j] += new_dist[i][j];
            }
        return;
    }
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        if(m==0) return -1;
        int n = grid[0].size();
        if(n==0) return -1;
        vector<vector<int>> dist_sum;
        bool first_building = true;
        // Iterate through all buildings
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 1)
                {
                    vector<vector<int>> new_dist = Dist2OneBuilding(grid,i,j);
                    distSum(dist_sum, new_dist);
                }
            }
        // Iterate through all empty spaces
        int min_dist = INT_MAX;
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 0)
                {
                    if(dist_sum[i][j] != -1 && dist_sum[i][j] < min_dist)
                        min_dist = dist_sum[i][j];
                }
            }
        if(min_dist == INT_MAX) min_dist = -1;
        return min_dist;
    }
};