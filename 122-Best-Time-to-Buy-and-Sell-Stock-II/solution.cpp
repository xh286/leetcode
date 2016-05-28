class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int entry_price = 0, exit_price = 0; 
        int total_profit = 0;
        bool has_long_position = false;
        int i = 0;
        for(i = 0; i < n-1; i++)// note: size_t i & n can fail this loop condition check when n == 0.
        {
            // Reason to buy is can sell at higher price later. 
            // Because of no limitation on frequency, just look ahead one step is enough.
            // Rule is: if increase next day, then buy previous day; if decrease next day, then sell previous day.
            // Constrained: if have long position, no buying; if no longer position, no selling.
            if( (has_long_position == false) && (prices[i+1] > prices[i]) ) // buy
            {
                entry_price = prices[i];
                has_long_position = true;
            }
            else if( (has_long_position == true) && (prices[i+1] < prices[i]) ) // sell
            {
                exit_price = prices[i];
                has_long_position = false;
                total_profit += exit_price - entry_price;
            }
        }
        // Now i = n-1.
        if(has_long_position == true) // last day, record paper profit too
        {
            exit_price = prices[i];
            has_long_position = false;
            total_profit += exit_price - entry_price;
        }
        return total_profit;
    }
};