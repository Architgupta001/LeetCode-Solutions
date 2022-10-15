```
    class Solution {
        public int maxArea(int[] height) {
            int i=0;
            int j=height.length-1;
            int ans = 0;
            while(i<j){
                int curr_sum = (height[i]<height[j])?(j-i)*height[i]:(j-i)*height[j];
                ans = Math.max(ans,curr_sum);
                if(height[i]<height[j]) i++;
                else j--;
            }
            return ans;
        }
    }
```
