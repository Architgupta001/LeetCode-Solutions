#include<bits/stdc++.h>

using namespace std;



int Lcs(string &s,string &t,int n,int m,vector<vector<int>> &dp)
{
	//base
	if(n<0 || m<0) return 0;

	if(dp[n][m]!=-1) return dp[n][m];

	if(s[n]==t[m])
	{
		return dp[n][m]=1+Lcs(s,t,n-1,m-1,dp);
	}

	return dp[n][m]=max(Lcs(s,t,n-1,m,dp),Lcs(s,t,n,m-1,dp));
}


int main()
{
	string s;
	string t;
	cin>>s>>t;

	int n=s.length();
	int m=t.length();

	vector<vector<int>> dp(n,vector<int>(m,-1));

	int ans=Lcs(s,t,s.length()-1,t.length()-1,dp);
	cout<<ans<<"\n";
	

}