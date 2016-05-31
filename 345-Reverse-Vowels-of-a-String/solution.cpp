class Solution {
public:
    string reverseVowels(string s) {
        string v; // stack of vowels
        string r = s; // result
        int n = s.size();
        for(int i=0; i<n; i++)
        {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
                v.push_back(s[i]);
        }
        for(int i=0; i<n; i++)
        {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            {
                r[i] = v.back();
                v.pop_back();
            }
        }
        return r;
    }
};