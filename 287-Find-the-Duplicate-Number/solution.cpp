class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Cannot sort. Note 4 is actually hint. I missed it.
        // Simple case is duplicated number appeared twice, then all numbers 1 - n are present in the array. Just add up all numbers, then subtract n(n+1)/2.
        // More complex case is duplicate number appeared three times, then a number is missing. This missing number can be found with the xor trick (array, plus 1 - n). The xor result is the missing number. Add it back, then becomes complete. Add up all numbers, subtract n(n+1)/2, then divide by 2.
        // If appeared four times, then 2 numbers missing. The xor result is the xor of the two missing numbers and the duplicate number. Cannot solve anymore.
        // The sum is not very effective. Example: 1 - 100, and all entries are 1, or 100. So the sum can have wide range.
        // What makes the duplicate number so special? Let's try the hash set route. Anyway to make it constant space? O(n) time, O(n) space.
        // Try the sort based method. binary search. The time complexity is very relaxed. That's a hint!
        
    }
};