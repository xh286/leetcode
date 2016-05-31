class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // a = prices. For any buy point i, the maximum profit is max(a[i+1 ... end]) - a[i]. We want to get maximum over all i.
        // So, first calculate the running maximum of a[] inversely.
        int n = prices.size();
        vector<int> b(n, 0); // assume prices are non-negative
        for(int i=n-2; i >= 0; i--)
        {
            b[i] = max(prices[i+1], b[i+1];

        }
        // b[n-1] is 0, b[n-2] is max(a[n-1:end]), b[i] is max(a[i+1:end]), b[0] is max(a[1:end]).
        int max_profit = 0; // minimum is zero
        for(int i=0; i < n-1; i++) // no point buying on last day
        {
            max_profit = max(max_profit, b[i] - prices[i]);
        }
        return max_profit;
    }
};