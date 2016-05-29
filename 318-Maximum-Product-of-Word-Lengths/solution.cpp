class Solution {
public:
    int maxProduct(vector<string>& words) {
        // brute force solution as first step
        int n = words.size();
        int maxproduct = 0;
        //vector<vector<int> > table(n, vector<int>(26,0));
        for(int i=0; i<n; i++)
        {
            for(int k = words[i].size() - 1; k >= 0; k--)
                table[i][words[i][k] - 'a']++;
        }
        for(int i=0; i<n; i++)
            for(int j=i+1; j<n; j++)
            {// check collision 
                bool collision = false;
                for(int k = 0; k < 26; k++)
                {
                    if(table[i][k] > 0 && table[j][k] > 0) // collision
                    {
                        collision = true;
                        break;
                    }
                }
                if(!collision)
                {
                    int product = words[i].size() * words[j].size();
                    if(product > maxproduct) 
                        maxproduct = product;
                }
            }
        }
        return maxproduct;
    }
};