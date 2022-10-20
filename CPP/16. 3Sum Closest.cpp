class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        int n = nums.size();
        vector<int> diff;
        vector<int> sum;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                for(int k=j+1;k<n;k++)
                {
                    int s = nums[i]+nums[j]+nums[k];
                    sum.push_back(s);
                    diff.push_back(abs(s-target));
                }
            }
        }
        int min=diff[0],loc=0;
        for(int i=0;i<diff.size();i++)
        {
            if(diff[i]<min)
            {
                min = diff[i];
                loc=i;
            }
        }
        
        return sum[loc];
    }
};