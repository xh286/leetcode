class Solution {
private:
    bool isCMatch(const char* s, const char* p)
    {
        // Recursion. Strings have an additional '\0' at the end (sentinel), can be used for probing.
        if(*p == '\0') return (*s == '\0'); // If pattern finished, matched if s is also finished.
        if(*p == '*'){
            if(*s == '\0') return isCMatch(s,p+1); // s finished, cannot move on. Consider * removed.
            // Otherwise, match s[0]. Example: p="*b", s="ab". * could match empty, or a, or ab.
            return (isCMatch(s,p+1) || isCMatch(s+1,p+1) || isCMatch(s+1,p));
        }
        if(*p == '?'){
            if(*s == '\0') return false;
            return isCMatch(s+1,p+1);
        }
        return (*p == *s) && isCMatch(s+1,p+1);
    }
public:
    bool isMatch(string s, string p) {
        return isCMatch(&s[0], &p[0]);
    }
};