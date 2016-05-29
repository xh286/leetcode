import java.util.HashSet;
public class Solution {
    public boolean containsDuplicate(int[] nums) {
        HashSet<Integer> detect_dup = new HashSet<Integer>(); //empty
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