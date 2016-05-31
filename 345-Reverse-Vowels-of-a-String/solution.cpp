class Solution {
private:
    bool charIsVowel(char c)
    {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
    }
public:
    string reverseVowels(string s) {
        string r = s; // result
        int n = s.size();
        int low = 0;
        int high = n-1;
        while(low<high) // rethink condition later
        {
            if(!charIsVowel(s[low]))
            {
                low++; 
                continue;
            }
            if(!charIsVowel(s[high]))
            {
                high--; 
                continue;
            }
        // Here both s[low] and s[high] are vowels, swap in r and move low/high closer.
            r[low] = s[high];
            r[high] = s[low];
            high--;
            low++;
        }
        return r;
    }
};