class Solution {
    /* Counting. Not necessarily go through all solutions.
       Count patterns for each length.
    
    */
private:
    void calc_keys_covered(vector<vector<vector<int>>>& covered, int x, int y)
    {
        int x_diff = abs((x-1)/3-(y-1)/3);
        int y_diff = abs((x-1)%3-(y-1)%3);
        if(max(x_diff,y_diff)==2)
        {
            switch(min(x_diff,y_diff))
            {
                case 2: covered[x-1][y-1].push_back(5); break;
                case 0: covered[x-1][y-1].push_back((x+y)/2); break;
                case 1: if(x+y == 7) {covered[x-1][y-1].push_back(2); covered[x-1][y-1].push_back(5);}
                        else if(x+y == 9){covered[x-1][y-1].push_back(4); covered[x-1][y-1].push_back(5);}
                        else if(x+y == 11){covered[x-1][y-1].push_back(5); covered[x-1][y-1].push_back(6);}
                        else if(x+y == 13){covered[x-1][y-1].push_back(5); covered[x-1][y-1].push_back(8);}
            }
        }
    }

    int numofPatterns(vector<vector<int>>& res, int k, vector<vector<vector<int>>>& covered) // calculate num of patterns for k using res from (k-1).
    {
        // Naive solution: Extend res with each of the remaining keys, and check validity.
        // rule 3: check if the line connecting res[i].back() and new key covers any other keys, if yes, check in set.
        vector<vector<int>> new_res;
        int n = res.size(); // each vector has length (k-1).
        for(int i=0; i<n; i++)
        {
            vector<bool> s(9,false);
            for(int j=0; j<k-1; j++)
                s[res[i][j]] = true;
            for(int j=0; j<9; j++)
                if(s[j]==false)
                {
                    bool valid = true;
                    if(k>=2)
                    {
                        // check line connecting x & y do not cross keys not in set
                        auto v = covered[res[i][k-2]-1][j-1];
                        for(int l=0; l<v.size(); l++)
                            if(!s[v[l]]) valid = false;
                    }
                    if(valid)
                    {
                        new_res.push_back(res[i]);
                        new_res.back().push_back(j+1);
                    }
                }
        }
        res = new_res;
        return res.size();
    }
public:
    int numberOfPatterns(int m, int n) {
        vector<vector<vector<int>>> covered(9, vector<vector<int>>(9, vector<int>()));
        for(int i=1; i<=9; i++)
            for(int j=1; j<=9; j++)
                calc_keys_covered(covered, i, j);
        int ret = 0;
        vector<vector<int>> res;
        res.push_back(vector<int>());
        int num;
        for(int k=1; k<=n; k++)
        {
            num = numofPatterns(res,k,covered);
            if(k>=m) ret += num;
        }
        return ret;
    }
};