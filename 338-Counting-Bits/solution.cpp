class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> a(num+1);
        int b = 1; // 2^x boundaries. Number of bits of [4, 5, 6, 7] are same as number of bits in [0, 1, 2, 3] plus 1.
        int i = 1; // counter
        a[0] = 0;
        while(i < num)
        {
            if(i == b) // hitting 2^x boundary, special processing
            {
                int n = (num+1) < b*2 ? (num+1) : b*2; // copy until right before next 2^x, or num
                while(i < n)
                {
                    a[i] = a[i-b] + 1;
                    i++;
                }
                b = b * 2;
            }
        }
    }
};