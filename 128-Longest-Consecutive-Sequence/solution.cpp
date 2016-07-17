class Solution {
/*
If integers not unique, make them unique.
If [ 1 2 2 3 4], return same result as [1 2 3 4].
Use a hash map, mapping to index in an array of ranges (start,end).
Given new entry x, if (x-1) and (x+1) not in hash set, insert it, and map to invalid index (-1).
If both (x-1) and (x+1) are in hash set, then it joins 3 segments into one. If one side is range, then join into that one. If both sides are range, then join into lower's range. If both sides single numbers, then both sides point to new range in vector.
If one of (x-1) and (x+1) are in hash set, then join with that side. If that side is range, then join into range, if is single number, then create new range.
Helper functions: joinLower, joinHigher, joinBoth.
Both map and vector need to be passed as parameters. Other parameters: iterators to the target to join.
*/
private:
    void makeUnique(vector<int>& nums, vector<int>& a)
    {
        unordered_set<int> st;
        for(auto it=nums.begin(); it!=nums.end(); it++)
            st.insert(*it);
        for(auto it=st.begin(); it!=st.end(); it++)
            a.push_back(*it);
    }
    void joinLower(unordered_map<int, int>& mp, vector<pair<int,int>>& vec, unordered_map<int, int>::iterator it)
    {
        // Join it->first+1 to the range/element ending at it->first
        if(it->second == -1) // element. Insert new range in vec, and let both start & end point to new range.
        {
            vec.push_back({it->first, it->first+1});
            it->second = vec.size()-1;
            mp[it->first+1] = it->second;
        }
        else // merge into existing range. Replace upper end. Increment length by 1.
        {
            int idx = it->second;
            vec[idx].second++;
            mp[it->first+1] = idx;
            mp.erase(it);
        }
    }
    void joinUpper(unordered_map<int, int>& mp, vector<pair<int,int>>& vec, unordered_map<int, int>::iterator it)
    {
        // Join it->first-1 to the range/element starting at it->first
        if(it->second == -1) // element. Insert new range in vec, and let both start & end point to new range.
        {
            vec.push_back({it->first-1, it->first});
            it->second = vec.size()-1;
            mp[it->first-1] = it->second;
        }
        else // merge into existing range. Replace upper end. Increment length by 1.
        {
            int idx = it->second;
            vec[idx].first--;
            mp[it->first-1] = idx;
            mp.erase(it);
        }
    }
    void joinBoth(unordered_map<int, int>& mp, vector<pair<int,int>>& vec, unordered_map<int, int>::iterator it, unordered_map<int, int>::iterator it2)
    {
        if(it->second == -1 && it2->second == -1) // create new range, point both to it.
        {
            vec.push_back({it->first, it2->first});
            it->second = vec.size()-1;
            it2->second = vec.size()-1;
        }
        else if(it->second == -1 && it2->second != -1)
        {
            int idx = it2->second;
            vec[idx].first -= 2;
            it->second = idx;
        }
        else if(it->second != -1 && it2->second == -1)
        {
            int idx = it->second;
            vec[idx].second += 2;
            it2->second = idx;
        }
        else // both sides are ranges, consolidate to lower range. Leave upper range in vec without ref.
        {
            int idx = it->second;
            int higher_end = vec[it2->second].second;
            vec[idx].second = higher_end;
            mp[higher_end] = it->second; // now both ends of new merged range point to same index in vec
            mp.erase(it);
            mp.erase(it2);
        }
    }
public:
    int longestConsecutive(vector<int>& nums) {
        vector<int> a;
        makeUnique(nums, a);
        vector<pair<int,int>> vec;
        unordered_map<int, int> mp;
        for(auto it=a.begin(); it!=a.end(); it++)
        {
            auto mpit = mp.find(*it-1);
            auto mpit2 = mp.find(*it+1);
            if(mpit!=mp.end() && mpit2!=mp.end())
                joinBoth(mp, vec, mpit, mpit2);
            else if(mpit!=mp.end() && mpit2==mp.end())
                joinLower(mp, vec, mpit);
            else if(mpit==mp.end() && mpit2!=mp.end())
                joinUpper(mp, vec, mpit2);
            else
                mp[*it] = -1; // insert into map, and map to invalid index in vec
        }
        int max_len = (nums.size()>0)?1:0;
        for(auto it=vec.begin(); it!=vec.end(); it++)
            max_len = max(max_len, it->second - it->start + 1);
        return max_len;
    }
};