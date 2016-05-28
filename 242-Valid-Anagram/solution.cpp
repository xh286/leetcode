class Solution {
public:
    bool isAnagram(string s, string t) {
        // Just verify the character frequencies are same between s & t.
        // For lowercase alphabets, we can just use a length 26 array to store.
        size_t n_s = s.size();
        size_t n_t = t.size();
        if(n_s != n_t) return false;
        std::vector<size_t> f_s(26,0); // initialize to zeros
        std::vector<size_t> f_t(26,0);
        size_t i;
        for(i=0; i<n_s; i++)
        {
            assert( ((s[i] - 'a') >= 0) && ((s[i] -'a') < 26) );
            f_s[s[i]-'a']++;
            assert( ((t[i] - 'a') >= 0) && ((t[i] -'a') < 26) );
            f_t[t[i]-'a']++;
        }
        // check that the characters got same frequency
        for(i=0; i<26; i++)
        {
            if(f_s[i] != f_t[i])
                return false;
        }
        return true;
    }
};