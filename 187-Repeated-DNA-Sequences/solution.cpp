class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        vector<string> ret;
        unordered_map<string,bool> mp;
        for(int i=0; i<=n-10; i++)
        {
            string t = s.substr(i,10);
            auto it = mp.find(t);
            if(it != mp.end())
            {
                if(!it->second)
                {
                    ret.push_back(t);
                    it->second = true;
                }
            }
            else
                mp[t] = false;
        }
        return ret;
    }
};