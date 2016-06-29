class Solution {
    
private:
    bool isReflected1D(vector<int>& x, int& y2) // x is non-empty
    {
        unordered_set<int> x_s;
        int x_min = x[0];
        int x_max = x[0];
        x_s.insert(x[0]);
        int n = x.size();
        for(int i=1; i<n; i++)
        {
            x_s.insert(x[i]);
            if(x[i] < x_min) x_min = x[i];
            else if(x[i] > x_max) x_max = x[i];
        }
        y2 = x_min + x_max;
        for(int i=0; i<n; i++)
        {
            if(x_s.find(y2-x[i]) == x_s.end())
                return false;
        }
        return true;
    }
public:
    bool isReflected(vector<pair<int, int>>& points) {
        // For sequence of (x0,xn-1) with same y, easy to solve. Find max, min over x, get average, then test (x1,..., xn-2) for existence of reflection in hash set.
        // But we have different y. So we store a hash set of y as well, if new y, then create new vector, otherwise, push into existing vector. We need map y value to vector index. Need a vector of vector.
        vector<vector<int>> v;
        unordered_map<int,int> y2i; // maps y to index in v
        int n = points.size();
        if(n==0) return true;
        for(int i=0; i<n; i++)
        {
            int y = points[i].second;
            int x = points[i].first;
            unordered_map<int,int>::iterator it = y2i.find(y);
            if(it != y2i.end())
            {
                v[it->second].push_back(x);
            }
            else
            {
                int new_idx = v.size();
                v.push_back(vector<int>());
                y2i[y] = new_idx;
                v[new_idx].push_back(x);
            }
        }
        n = v.size();
        int last_y2, y2;
        if(!isReflected1D(v[0]), y2)
            return false;
        last_y2 = y2;
        for(int i=1; i<n; i++)
        {
            if(!isReflected1D(v[i], y2) || y2 != last_y2)
                return false;
            else
                last_y2 = y2;
        }
        return true;
    }
};