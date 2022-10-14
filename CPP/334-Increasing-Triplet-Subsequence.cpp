class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if(n<3) return false;

        vector<int> leftMin(n) ,rightMin(n);
        leftMin[0]=nums[0];
        for(int i=1;i<n;i++){
            leftMin[i]=min(nums[i],leftMin[i-1]);
        }
        rightMin[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            rightMin[i]=max(nums[i],rightMin[i+1]);
        }
        for(int i=1;i<n-1;i++){
            if(leftMin[i-1] < nums[i] && nums[i] < rightMin[i+1]) return true;
        }
        return false;
    }
};