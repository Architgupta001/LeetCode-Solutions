class Solution 
{
public:
    bool checkSubarraySum(vector<int>& nums, int k) 
    {
        unordered_map<int,int>m;
        // key is the remainder 
        // value is the index
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            int rem=sum%k;
            if(rem==0 && i>0)
            {
                return true;
            }
            if(m.find(rem)==m.end())
            {
                m[rem]=i;
            }
            else if(i-m[rem]>=2)
            {
                return true;
            }
        }
        return false;
    }
};