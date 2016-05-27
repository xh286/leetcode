class Solution {
public:
    string reverseString(string s) {
        string t;
        t.resize(s.length()); // same length as s
        std::string::reverse_iterator iter_in = s.rbegin(); // reverse iterator
        std::string::iterator iter_out = t.begin();
        std::string::reverse_iterator iter_end = s.rend();
        while(iter_in != iter_end)
        {
            *iter_out = *iter_in;
            iter_in++;
            iter_out++;
        }
        return t;
    }
};