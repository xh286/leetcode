class Solution {
public:
    int maxArea(vector<int>& height) {
        // Total n^2 pairs, area for each pair is min*dist O(1), so naive solution n^2.
        // DP: no idea. Complex. 
        // Plotting examples: found: from left side, only need to track an increasing sequence. Same from right side.
        // So, probably faster than n^2. Worst case is: 1,2,3,...k,...3,2,1.
        // But looking at this we see that any <= need to be skipped.
        int n = height.size();
        int water = 0;
        int low = 0;
        int high = n-1;
        while(low<high)
        {
            int h = min(height[low],height[high]);
            water = max(water,(high-low)*h);
            while(low<high && height[low]<=h) low++;
            while(low<high && height[high]<=h) high--;
        }
        return water;
    }
};