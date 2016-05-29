import java.util.HashSet;
public class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        int n = nums1.length;
        if(nums2.length < n)
        {
            n = nums2.length;
        }
        int[] a = new int[n];
        int i = 0;
        HashSet<Integer> nums1_set = new HashSet<Integer>(); // empty set
        for(int x: nums1)
        {
            nums1_set.add(x); // if duplicate don't add.
        }
        for(int y: nums2)
        {
            if(nums1_set.contains(y))
            {
                a[i] = y;
                i = i + 1;
            }
        }
        int[] b = new int[i-1]; // output, copy a[0:i-2] to b.
        for(i = 0; i < i - 1; i ++)
        {
            b[i] = a[i];
        }
        return b;
    }
}