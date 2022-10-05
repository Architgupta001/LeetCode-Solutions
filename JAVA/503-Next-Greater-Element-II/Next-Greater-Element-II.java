class Solution {
    public int[] nextGreaterElements(int[] nums) {
        int n = nums.length;
        Stack<Integer> st = new Stack<>();
        int[] ans = new int[n];
        for(int i=n-1; i>=0; i--){
            st.push(nums[i]);
        }
        for(int i=n-1; i>=0; i--){
            int elem = nums[i];
            while(st.size() != 0 && st.peek() <= elem){
                st.pop();
            }
            if(st.size() == 0){
                ans[i] = -1;
            }else{
                ans[i] = st.peek();
            }
            st.push(elem);
        }
        return ans;
    }
}