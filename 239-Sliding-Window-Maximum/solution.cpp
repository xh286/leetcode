class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // Using a deque<int>. 
        // Output: always queue front. Queue won't be empty as max always exists.
        // Push: if has new inputs, while(back < new) pop_back, then push new. If no more inputs, end.
        // Pop: if front == new fallout, then pop.
        deque<int> dq;
        int n = nums.size();
        //assert(k >= 1 && k <= n);
        vector<int> r;
        if(n==0) return r;
        dq.push_back(nums[0]);
        int i = 1;
        for(; i < k; i++)
        {
            while(!dq.empty() && dq.back() < nums[i]) dq.pop_back();
            dq.push_back(nums[i]);
        }
        for(; i < n; i++)
        {
            int fallout = nums[i-k];
            this_max = dq.front();
            r.push_back(this_max);
            if(this_max == fallout) dq.pop_front();
            while(!dq.empty() && dq.back() < nums[i]) dq.pop_back();
            dq.push_back(nums[i]);
        }
        return r;
    }
};