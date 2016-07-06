class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        if(s.size()==0) return true;
        for(auto it=s.begin(); it!=s.end(); it++)
        {
            string t(s.begin(), it+1);
            if(wordDict.find(t)!=wordDict.end())
                if(wordBreak(string(it+1,s.end()),wordDict))
                    return true;
        }
        return false;
    }
};