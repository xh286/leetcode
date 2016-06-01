class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int num_to_add = 1;
        // need to consider empty input as well
        for(int i = n-1; i >= 0; i--)
        {
            if(num_to_add > 0) // add the num to this digit
            {
                digits[i] = (digits[i] + num_to_add) % 10;
                if( (digits[i] + num_to_add) >= 10 )
                    num_to_add = 1;
                else
                    num_to_add = 0;
            }
            else
                break;
        }
        // if i == -1, overflow, in that case, insert "1" at the beginning
        if(num_to_add > 0)
        {
            digits.insert(0, num_to_add);
        }
        return digits;
    }
};