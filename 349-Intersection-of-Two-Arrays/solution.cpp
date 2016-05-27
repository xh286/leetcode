#include<unordered_set>
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // The requirements strongly suggest using hash set. Actually two hash sets.
        std::unordered_set<int> set1, set2;
        size_t i, len1, len2;
        len1 = nums1.size();
        len2 = nums2.size();
        for(i=0; i<len1; i++)
        {
            set1.insert(nums1[i]);
        }
        // Now the unique elements of nums1 are in set1.
        for(i=0; i<len2;i++)
        {
            if(set1.find(nums2[i]) != set1.end())//if element in nums2 found in set1
            {
                set2.insert(nums2[i]);
            }
        }
        // Now the unique elements of intersection are in set2.
        std::vector<int> intersection;
        std::unordered_set<int>::const_iterator it;
        for(it=set2.begin(); it != set2.end(); ++it)
        {
            intersection.push_back(*it);
        }
        return intersection;
    }
};