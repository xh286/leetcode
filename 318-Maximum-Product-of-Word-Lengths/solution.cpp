class Solution {
public:
    int maxProduct(vector<string>& words) {
        // brute force solution as first step
        int n = words.size();
        int maxproduct = 0;
        vector<unsigned int> table(n,0);
        for(int i=0; i<n; i++)
        {
            int len = words[i].size();
            for(int k = 0; k < len; k++)
                table[i] |= 1 << (words[i][k] - 'a');
        }
        
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {// check collision 
                if((table[i] & table[j]) == 0)
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