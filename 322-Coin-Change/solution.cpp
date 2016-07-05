class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // If amount greater than max(coins), then the last coin is any one of them. Then find # for the reduced amount, and take min over the range. If amount exact matches, then return 1. If amount < coin value, then don't consider it.
        // Or we can use DP, from 1 up to amount. Either use system stack space, or heap space.
        
        // assume positive coin values! Otherwise more complex.
        if(amount<0) return -1;
        if(amount==0) return 0;
        int m = coins.size();
        if(m==0) return -1;
        std::sort(coins.begin(), coins.end()); // sort coins in ascending order
        vector<int> ncoins(amount+1,-1); // complexity amount*coins
        ncoins[0] = 0;
        for(int i=1; i<=amount; i++) // calculate min # coins for each amount
            for(int j=0; j<m; j++)
            {
                if(i>=coins[j])
                {
                    int pre = ncoins[i-coins[j]];
                    if(pre!=-1)
                    {
                        if((ncoins[i] == -1) || (pre+1 < ncoins[i]))
                            ncoins[i] = pre+1;
                    }
                }
                else
                    break;
            }
        return ncoins[amount];
    }
};