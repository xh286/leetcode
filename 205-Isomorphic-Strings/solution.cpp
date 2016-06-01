class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // Many rules: 1. All occurrences of a character must be replaced with same character. 2. Cannot replace two different characters with same character. So: same->same, different->different.
        // Solution: use a hash map since it's not clear which character set is used, UTF-8? ASCII? lower case alphabets?
        unordered_map<char, char> char_map;  // On Linux, char will be UTF-8 by default.
        unordered_set<char> mapped_chars;
        int n = s.size();
        for(int i=0; i<n; i++)
        {
            unordered_map<char, char>::iterator it = char_map.find(s[i]); // check if s[i] already mapped
            if(it == char_map.end()) // not mapped yet, add mapping
            {
                unordered_set<char>::iterator it2 = mapped_chars.find(t[i]);
                if(it2 != mapped_chars.end()) // trying to map two chars to same char
                    return false;
                char_map.insert({s[i],t[i]});
                mapped_chars.insert(t[i]);
            }
            else // mapped, check consistency of mapping
            {
                if(it->second != t[i]) // same character mapped to two different characters
                    return false;
            }
        }
        return true;
    }
};