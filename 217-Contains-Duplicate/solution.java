
public class Solution {
    public boolean containsDuplicate(int[] nums) {
        HashSet<int> detect_dup = new HashSet<int>(); //empty
        for(int x: nums)
        {
            if(detect_dup.contains(x))
                return true;
            else
                detect_dup.add(x);
        }
        return false;
    }
}