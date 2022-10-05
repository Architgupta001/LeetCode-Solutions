class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n=nums.size();

        /*
        bits[i][j] will store number of set bits 
        at jth position in first i+1 elements
        */
        vector<vector<int>> bits(n,vector<int>(31,0));
        for(int i=0;i<n;i++){
            int x=nums[i];
            for(int j=0;j<31;j++){
                bits[i][j]=1&(x>>j);
                if(i)bits[i][j]+=bits[i-1][j];
            }
        }
        /*
        mx(i) will store the maximum possible OR of subarray starting at index=i
        */
        vector<int> mx(n,0);
        int mxor=0;
        for(int i=n-1;i>=0;i--){
            mxor|=nums[i];
            mx[i]=mxor;
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            int l=1,r=n-i;
            int sres=r;
            /*
            doing the binary search on length to find the minimum length subarray with OR remains same as mx(i)
            */
            while(l<=r){
                int m=(l+r)/2;
                int j=i+m-1;
                int z=0;
                for(int k=0;k<31;k++){
                    int y=bits[j][k]-(i>0?bits[i-1][k]:0);
                    if(y)
                    z+=(1<<k);
                }
                if(z==mx[i]){
                    r=m-1;
                    sres=m;
                }else l=m+1;
            }
            /*
            storing the minimum length of subarray for index=i
            */
            ans.push_back(sres);
        }
        return ans;
    }
};