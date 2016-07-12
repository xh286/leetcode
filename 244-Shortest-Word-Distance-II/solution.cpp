class WordDistance {
private:
    int minDist(set<int>& set1, set<int>& set2) // minimum distance between two sorted sets, int values 0...INT_MAX.
    {
        int ret = INT_MAX;
        auto it1 = set1.begin();
        auto it2 = set2.begin();
        while(it1 != set1.end() && it2 != set2.end())
        {
            int dist;
            if(*it1 > *it2)
            {
                dist = *it1 - *it2;
                it2++;
            }
            else if(*it1 < *it2)
            {
                dist = *it2 - *it1;
                it1++;
            }
            else
            {
                ret = 0; break;
            }
            ret = min(ret, dist);
        }
        return ret;
    }
    unordered_map<string, set<int>> mp;
public:
    WordDistance(vector<string>& words) {
        int n = words.size();
        for(int i=0; i<n; i++)
            mp[words[i]].insert(i);
    }

    int shortest(string word1, string word2) {
                // assume both words in the list
        return minDist(mp[word1], mp[word2]);
    }
};


// Your WordDistance object will be instantiated and called as such:
// WordDistance wordDistance(words);
// wordDistance.shortest("word1", "word2");
// wordDistance.shortest("anotherWord1", "anotherWord2");