// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        // Search in an array of [0...0 1...1]. Maintain invariant: high points to 1, low points to 0.
        int low = 1, high = n;
        if(isBadVersion(low)) return 1; // try to opt away this
        while(high-low>1) // reduce range until low+1==high, return high.
        {
            int mid = low + (high-low)/2;
            if(isBadVersion(mid)) high = mid;
            else low = mid;
        }
        return high;
    }
};