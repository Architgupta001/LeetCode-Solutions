class Solution {
public:
    int mod = 1e9 + 7;
	int solve(int n, int k , int t , vector<vector<int>>& dp){
		if(n < 0 or t < 0) return 0;
		if(t == 0 and n == 0) return 1;
		if(dp[n][t] != -1) return dp[n][t];
		long long ans = 0;
		for(int i = 1 ; i <= k ; i++){
			ans += solve(n-1,k,t-i,dp);
			ans %= mod;
		}
		return dp[n][t] = ans;
	}
	int numRollsToTarget(int n, int k, int target) {
		vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
		int ans = solve(n,k,target,dp);
		return ans;
	}
};