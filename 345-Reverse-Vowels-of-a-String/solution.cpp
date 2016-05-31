class Solution {
public:
    string reverseVowels(string s) {
        vector<char> v; // stack of vowels
        string r = s; // result
        int n = s.size();
        for(int i=0; i<n; i++)
        {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                v.push_back(s[i]);
        }
        for(int i=0; i<n; i++)
        {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            {
                r[i] = v.back();
                v.pop_back(s[i]);
            }
        }
        return r;
    }
};