// Leetcode question 62. Unique Paths 

#include <iostream>
using namespace std;

int uniquePaths(int m, int n) { 
        
    int dp[m][n];
    
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            if(i==0||j==0)
                dp[i][j] = 1;
    
    for(int i=1; i<m; i++)
        for(int j=1; j<n; j++)
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
    
    return dp[m-1][n-1];
}

int main() {
    int m,n;
    cout<<"Enter number of rows and columns: ";
    cin>>m>>n;
    cout<<"Number of unique paths from top-left to bottom-right corner are: "<<uniquePaths(m,n)<<endl;
    return 0;
}
