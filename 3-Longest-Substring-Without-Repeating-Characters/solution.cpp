class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Maintain a hash map of substring characters. Check whether a[j] got duplicate in hash map.
        // If duplicates with a[i] in hash map, erase all the chars up to a[i], and remember i.
        // Before erase, update max_len with hash_set size. After loop complete, also update max_len.
        // Need to remember next_i to erase.
        // Hash map can be simple ASCII array if string is ASCII.
        unordered_map<char,int> c2i;
        int n = s.size();
        int erase_start = 0;
        int max_len = 0;
        for(int i=0; i<n; i++)
        {
            auto it = c2i.find(s[i]);
            if(it != c2i.end())
            {
                max_len = max(max_len, c2i.size());
                int j = it->second;
                // erase s[erase_start...j]
                for(int k = erase_start; k <= j; k++)
                    c2i.erase(s[k]);
                erase_start = j+1;
            }
            c2i[s[i]] = i;
        }
        max_len = max(max_len, c2i.size());
        return max_len;
    }
};