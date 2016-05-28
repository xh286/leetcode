class Solution {
public:
    int maxProfit(vector<int>& prices) {
        size_t n = prices.size();
        int entry_price = 0, exit_price = 0; 
        int total_profit = 0;
        bool has_long_position = false;
        size_t i = 0;
        for(i = 0; i < n-1; i++)
        {
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