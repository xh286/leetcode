public class Solution {
    public int bulbSwitch(int n) {
        // naive solution would be O(n^2) time, O(1) space.
        // Could do better. Only requires return a number.
        // Perfect squares are odd factors, e.g. 9 has 1, 3, 9 as factors. So only perfect squares get set in the end.
        return Math.sqrt(n);
        
    }
}