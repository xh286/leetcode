import java.lang.*
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;

public class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        int[] output = new int[Math.min(nums1.length, nums2.length)]; // output at most as long as the shorter of nums1, nums2.
        // Build the frequency table of both nums1 and nums2
        HashMap<Integer, Integer> nums1_map = new HashMap<Integer, Integer>();
        HashMap<Integer, Integer> nums2_map = new HashMap<Integer, Integer>();
        for(int x: nums1)
        {
            if(nums1_map.containsKey(x))
            {
                nums1_map.put(x, nums1_map.getValue(x)+1);
            }
            else
            {
                nums1_map.put(x,1);
            }
        }
        for(int x: nums2)
        {
            if(nums2_map.containsKey(x))
            {
                nums2_map.put(x, nums2_map.getValue(x)+1);
            }
            else
            {
                nums2_map.put(x,1);
            }
        }
        // frequency tables ready, now iterate the smaller map and lookup in larger map to get output
        int i = 0;
        for(Map.Entry<Integer,Integer> it : nums1_map)
        {
            int k = it.getKey();
            if(nums2_map.containsKey(k)) // intersection found
            {
                int d = Math.min(nums1_map.get(k), nums2_map.get(k));
                // now output d times
                for(int j = 0; j < d; j++)
                {
                    output[i] = k;
                    i++;
                }
            }
        }
        // set output[i - end] to null.
        for(; i < output.length; i++)
        {
            output[i] = null;
        }
        return output;
    }
}