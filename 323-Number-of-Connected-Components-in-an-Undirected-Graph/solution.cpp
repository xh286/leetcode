class Solution {
private:
    void visitVertex(const vector<vector<int>>& graph, int i, vector<bool>& visited)
    {
        visited[i] = true;
        for(int k=0; k<graph[i].size(); k++)
        {
            int j = graph[i][k];
            if(!visited[j])
                visitVertex(graph, j, visited);
        }
    }
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        vector<vector<int>> graph(n,vector<int>()); // adjacency list
        int e = edges.size();
        for(int k=0; k<e; k++)
        {
            int i = edges[k].first;
            int j = edges[k].second;
            graph[i].push_back(j);
            graph[j].push_back(i);
        }
        int components = 0;
        vector<bool> visited(n,false);
        for(int i=0; i<n; i++)
        {
            if(!visited[i]) components++;
            visitVertex(graph, i, visited);
        }
        return components;
    }
};