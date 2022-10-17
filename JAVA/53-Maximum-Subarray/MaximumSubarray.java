class Solution {
    public int maxSubArray(int[] nums) {
        int max=Integer.MIN_VALUE, cur=0;
        for(int i:nums){
            if(cur<0)
                cur = 0;
            cur += i;
            max = Math.max(max, cur);
        }
        return max;
    }
}