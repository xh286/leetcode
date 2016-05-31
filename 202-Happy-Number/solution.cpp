class Solution {
private:
    int sumOfDigitsSquare(int n)
    {
        int result = 0;
        while(n)
        {
            result += (n%10) * (n%10);
            n /= 10;
        }
        return result;
    }
public:
    bool isHappy(int n) {
        if (n<=0) return false; // if not positive, not happy number
        bool result = false;
        unordered_set<int> history;
        history.insert(n);
        while(true)
        {
            n = sumOfDigitsSquare(n);
            if(n == 1)
            {
                result = true; break;
            }
            else if (history.find(n) != history.end()) // if non-one entry collision, not happy
            {
                result = false; break;
            }
        }
        return result;
    }
};