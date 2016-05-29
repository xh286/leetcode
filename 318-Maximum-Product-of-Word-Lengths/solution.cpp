class Solution {
public:
    int maxProduct(vector<string>& words) {
        // brute force solution as first step
        int n = words.size();
        int maxproduct = 0;
        vector<int> l_words; // lengths of (original) words;
        vector<vector<int> > table(n, vector<int>(26,0));
        vector<string> c_words(n); // converted words. IN each word, characters are unique and ascending.
        for(int i=0; i<n; i++)
        {
            l_words[i] = words[i].size();
            for(int k = 0; k < l_words[i]; k++)
                table[i][words[i][k] - 'a']++;
            for(int k = 0; k < 26; k++)
                if(table[i][k] > 0)
                    c_words[i].push_back('a'+k);
        }
        
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {// check collision 
                bool collision = false;
                for(int p = 0, q = 0; p < c_words[i].size() && q < c_words[j].size();)
                {
                    if(c_words[i][p] < c_words[j][q])
                        p++;
                    else if(c_words[i][p] > c_words[j][q])
                        q++;
                    else // (c_words[i][p] == c_words[j][q]) // collision
                    {
                        collision = true;
                        break;
                    }
                }
                if(!collision)
                {
                    int product = l_words[i] * l_words[j];
                    if(product > maxproduct) 
                        maxproduct = product;
                }
            }
        }
        return maxproduct;
    }
};