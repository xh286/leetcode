class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Partition solution like this: Either sell at nth element, or not.
        // Define f(2,n) as max profit, then f(2,n-1) if not sold at n.
        // If sold at n, then last buy point iterate over 0-(n-1), so f(2,n) is a[n]-a[j]+f(1,j).
        // Note it's not f(1,j-1). If a[j-1]<a[j], we would have missed the profit a[j]-a[j-1].
        // Also note, the solution is not partitioned into "best solution ending at i", but "solution up to i".
        // So, max only over 2 cases in the end, but (n-1) cases before that.
        // In general, for i in {1,...n-1}. f(2,i) = max(f(2,i-1),max(a[i]-a[j]+f(1,j)) over j in {0,...,i-1}).
        // This can be factored into: f(2,i) = max(f(2,i-1),a[i]+max(f(1,j)-a[j]) over j in {0,...,i-1}).
        // Define u[i] = max(f(1,j)-a[j]) over j in {0,...,i-1}. Then u[i] can be calculated in linear time.
        // Here f(1,i) = max(f(1,i-1),a[i]+u[i]) where u[i] = max(-a[j]) over j in {0,...,i-1}.
        // So we can see u and f overwritten during each round.
        int n = prices.size();
        vector<int>& a = prices;
        vector<int> f(n,0); // init to f(0,i).
        vector<int> u(n,0);
        int K = 2; // run 2 iterations
        for(int k=1; k<=K; k++)
        {
            for(int i=1; i<n; i++)
            {
                u[i] = max(u[i-1], f[i-1]-a[i-1]);
            }
            for(int i=1; i<n; i++)
            {
                f[i] = max(f[i-1], a[i]+u[i]);
            }
        }
        return f[n-1];
    }
};