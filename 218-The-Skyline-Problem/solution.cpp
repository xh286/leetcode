class Solution {
    
// 1. Examples:
// A. [1 100 100], [2 99 99], [3 98 98], so number of overlaps is 1 to ~50, or O(n).
// Similar overlap, but different order of heights. E.g. [1 100 1], [2 99 2], [3 98 3]...
// B. Could be disjoint, e.g. there's street in between.
// 2. Operations:
// A. Change only possible at new Li, or old Ri falling out. If consecutive points same height, extend/update previous, no new insert.
// B. New Li: insert into set, also update set, remove all ranges that had fallen out. Total n.
// C. Old Ri falling out. This can happen before new Li insert. Total also n.
// D. Find max of "current set". Current set is defined as when a Ri falls out, or new Li is inserted.
// E. The set is always triplet. Always maintain max(Hi). Always maintain min of Ri.
// F. Procedure is like: Loop over Li. But before insert Li, check all those Ri <= Li, remove them from set one by one, and generate key points. 
// H. Special case: If set is empty.
// Uniqueness is easy, just check if new Hi equals lastHi. Set lastHi to 0 at the beginning.
// Assume no two buildings exactly overlap each other.
// Each time after falls out, or insert, update max height.
private:
    int getMaxHeight(map<int,int>& mp)
    {
        int maxheight = 0;
        for(auto it=mp.begin(); it!=mp.end(); it++)
            maxheight = max(maxheight, it->second);
        return maxheight;
    }
    
    void insertNewPoint(vector<pair<int,int>>& ret, map<int,int>& mp, int Loc)
    {
        int height = getMaxHeight(mp);
        if(ret.empty() || height != ret.back().second)
        {
            ret.push_back(make_pair(Loc, height));
        }
    }
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        int n = buildings.size();
        map<int,int> mp; // Sorted by Ri, mapped to Hi. Unique Ri. If same Ri, keep larger Hi.
        vector<pair<int,int>> ret;
        for(int i=0; i<n; i++)
        {
            int Li = buildings[i][0];
            int Ri = buildings[i][1];
            int Hi = buildings[i][2];
            // Fall out
            while(!mp.empty())
            {
                auto it = mp.begin();
                int old_Ri = it->first;
                if(old_Ri <= Li) // previous range falls out
                    mp.erase(it);
                else
                    break;
                if(old_Ri < Li) // no need if equal, will be handled by insertion
                    insertNewPoint(ret, old_Ri);
            }
            // Insert
            auto it = mp.find(Ri);
            if(it != mp.end()) // new and old building same Ri
                it->second = max(it->second,Hi);
            else
                mp[Ri] = Hi;
            insertNewPoint(ret, Li);
        }
        while(!mp.empty())
        {
            auto it = mp.begin();
            int old_Ri = it->first;
            mp.erase(it);
            insertNewPoint(ret, old_Ri);
        }
        return ret;
    }
};










