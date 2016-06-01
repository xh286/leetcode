class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size();
        vector<int> b_s(10,0); // 10 buckets for 10 digits 0 - 9.
        vector<int> b_g(10,0);
        // go through secret & guess simultaneously, count bulls and count all others into their buckets.
        int bulls = 0;
        for(int i=0; i<n; i++)
        {
            if(secret[i] == guess[i])
            {
                bulls++;
            }
            else
            {
                b_s[secret[i] - '0']++;
                b_g[guess[i] - '0']++;
            }
        }
        int cows = 0;
        for(int i=0; i<10; i++)
        {
            cows += min(b_s[i], b_g[i]);
        }
        // Now generate output. Note that bulls and cows can be multiple digits
        std::ostringstream temp;
        temp << bulls << 'A' << cows << 'B';
        string s = temp.str();
        return s;
    }
};