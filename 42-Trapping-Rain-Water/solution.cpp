class Solution {
public:
    int trap(vector<int>& height) {
        // Use stack to store a decreasing sequence of val+count pair. The sequence starts at the current running max.
        // The sum of counts in the stack equals the number of entries from running max to current entry.
        // If a[i] >= previous running max, then fill all entries in stack up to previous running max, clear stack and insert {a[i],1}.
        // If a[i] < previous running max, but >= stack top, keep popping stack until stack top > a[i], fill all popped to a[i], and consolidate into {a[i], count} where count is total count of popped, plus 1.
        // If a[i] < stack top, just insert {a[i],1}.
        // If we don't keep pairs, just a[i] in stack, and keep multiple copies of same values, then worst case (V shape), then time complexity would be n^2.
        int running_max = 0;
        int water = 0;
        stack<pair<int,int>> t_stack;
        int n = height.size();
        for(int i=0; i<n; i++)
        {
            if(a[i] >= running_max)
            {
                while(!t_stack.empty())
                {
                    auto val_count = t_stack.top();
                    water += (running_max - val_count.first)*val_count.second;
                    t_stack.pop();
                }
                t_stack.push({a[i],1});
                running_max = a[i];
            }
            else // a[i] < running_max
            {
                int count = 1;
                while(!t_stack.empty())
                {
                    // fill up to a[i] level
                    auto val_count = t_stack.top();
                    if(a[i] < val_count.first) break;
                    water += (a[i] - val_count.first)*val_count.second;
                    count += val_count.second;
                    t_stack.pop();
                }
                t_stack.push({a[i],count});
            }
        }
        return water;
    }
};