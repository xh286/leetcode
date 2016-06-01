class Solution {
private:
    string lcp(string s, string t)
    {
        int n = min(s.size(),t.size());
        string r;
        for(int i=0; i<n; i++)
        {
            if(s[i] == t[i])
                r.push_back(s[i]);
            else
                break;
        }
        return r;
    }
public:
    string longestCommonPrefix(vector<string>& strs) {
        string r;
        int n = strs.size();
        if(n==0) return r;
        r = strs[0];
        for(int i=1; i<n; i++)
        {
            r = lcp(r, strs[i]);
            if(r.size() == 0)
                break;
        }
        return r;
    }
};