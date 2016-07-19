class Solution {
    /*  Idea is DFS, each time consume 1 or 2 chars (if the 2-char combination is between 10 to 26).
        Increment count (data member of class, or pass by reference as a function parameter) when string is consumed.
        Use C++ substring function s.substr(start, len) to generated unconsumed part.
        Assume input string is only digits. But could be invalid.
        Special case: 0. If encounter 0 as start of string, return directly.
    */
    bool TwocharCombValid(string s)
    {
        if(s[0] == '1') return true;
        if(s[0] == '2' && s[1] <= '6') return true;
        return false;
    }
    void DFS(string s, int& count)
    {
        int total_len = s.size();
        if(total_len == 0)
        {
            count++; return;
        }
        // total_len >= 1
        if(s[0] == '0') return;
        DFS(s.substr(1,total_len-1),count);
        if(total_len >= 2 && TwocharCombValid(s.substr(0,2)))
        {
            DFS(s.substr(2,total_len-2),count);
        }
    }
public:
    int numDecodings(string s) {
        if(0 == s.size()) return 0;
        int count = 0;
        DFS(s,count);
        return count;
    }
};