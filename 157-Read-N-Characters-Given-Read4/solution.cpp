// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int m = 0;
        while(m<n)
        {
            int k = read4(buf+m);
            m += k;
            if(k<4) break;
        }
        return min(m,n);
    }
};