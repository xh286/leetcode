class Solution {
public:
    int maxProduct(vector<string>& words) {
        // brute force solution as first step
        int n = words.size();
        int maxproduct = 0;
        for(int i=0; i<n; i++)
        {
            //build a frequency table
            vector<int> table_i (26,0); // 26 characters, no need for hash set
            for(int k = words[i].size() - 1; k >= 0; k--)
                table_i[words[i][k] - 'a']++;
            //check for collision
            for(int j=i+1; j<n; j++)
            {
                bool collision = false;
                for(int k = words[j].size() - 1; k >= 0; k--)
                {
                    if(table_i[words[j][k] - 'a'] > 0) // collision
                    {
                        collision = true;
                        break;
                    }
                }
                if(!collision)
                {
                    int product = words[i].size() * words[j].size();
                    if(product > maxproduct) maxproduct = product;
                }
            }
        }
        return maxproduct;
    }
};