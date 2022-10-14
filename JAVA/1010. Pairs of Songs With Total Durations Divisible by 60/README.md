<pre>
class Solution {
    public int numPairsDivisibleBy60(int[] time) {
        for (int i = 0; i < time.length; i++) {
            time[i] = time[i] % 60;
        }
        
        int[] map = new int[60];
        int result = 0;
        
        for (int t: time) {
            if (t == 0) {
                result += map[0];
            } else {
                result += map[60 - t];
            }            
            map[t]++;
        }
        
        return result;
    }
}
</pre>
