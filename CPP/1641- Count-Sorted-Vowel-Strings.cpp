class Solution {
public:
    void solve(int n, int& ans, vector<int>& dp, int i)
    {
        if(n==0)
        {
            ans++;
            return;
        }
        int a = 0;
        
        for(;i<5;i++)
        {
            solve(n-1,ans,dp,i);
        }
    }
    int countVowelStrings(int n) 
    {
        int ans = 0;
        vector<int> dp(n+1, -1);
        
        solve(n,ans,dp,0);
        return ans;
    }
};