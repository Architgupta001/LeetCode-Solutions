class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        sort(nums.begin(),nums.end());
        int len=1;
        int mx=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums [i-1]+1==nums[i])
            {
                len++;
                mx=max(len,mx);
            }
            else if(nums[i-1]==nums[i])
                continue;
            else
                len=1;
        }
        return mx;
    }
};
