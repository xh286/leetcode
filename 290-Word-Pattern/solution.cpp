class Solution {
public:
    bool wordPattern(string pattern, string str) {
        // The mapping between a character in a to a word in b should satisfy these conditions:
        // 1. Number of chars in a equals number of words in b.
        // 2. 1 char cannot map to more than 1 word, and no more than 1 char can map to a word.
        // This is same as the isomorphic string problem, except chars in b replaced by words.
        // First break str into vector of words.
        vector<string> b;
        int n = str.size();
        string temp;
        for(int i=0 ; i<n; i++) // can handle leading spaces and trailing spaces, and multiple spaces between words
        {
            if(str[i] == ' ')
            {
                if(temp.size() > 0)
                {
                    b.push_back(temp);
                    temp.clear();
                }
                continue;
            }
            temp.push_back(str[i]);
        }
        if(temp.size() > 0) // last word
        {
            b.push_back(temp);
            temp.clear();
        }
        string& a = pattern; // reference, easier to type
        // check size equal, otherwise no way for one-to-one mapping
        if(a.size() != b.size()) return false;
        // check 1-to-1 relationship.
        unordered_map<char,string> char2str_map;
        unordered_set<string> mapped_strings;
        for(int i=0; i<n; i++)
        {
            unordered_map<char,string>::iterator it = char2str_map.find(a[i]);
            if(it != char2str_map.end()) // found, mapped before
            {
                if(it->second != b[i]) // string comparison.
                    return false;
            }
            else // not mapped before, try to insert
            {
                unordered_set<string>::iterator it2 = mapped_strings.find(b[i]);
                if(it != mapped_strings.end()) // this string is mapped before
                {
                    return false;
                }
                else
                {
                    char2str_map.insert({a[i],b[i]});
                    mapped_strings.insert(b[i]);
                }
            }
        }
        return true;
    }
};