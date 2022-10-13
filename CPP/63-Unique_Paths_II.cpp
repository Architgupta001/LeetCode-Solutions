class Solution {
public:
    int dfs(vector<vector<int>>& obstacleGrid,int i,int j,vector<vector<int>> &dp,int m ,int n)
    {
        // if current cell value is not inside the boundary then we can not proceed further return 0
        if(i<0 || j<0 || i>=m || j>=n || obstacleGrid[i][j]==1)
            return 0;
        
        // if we have already computed the value then no need to calvulate it again
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        
        // if we have on last cell then tsake it as a path and return 1
        if(i==m-1 && j==n-1)
        {    
            return 1;
        } 
        return dp[i][j]=dfs(obstacleGrid,i,j+1,dp,m,n)+dfs(obstacleGrid,i+1,j,dp,m,n);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        int m=obstacleGrid.size();      // no. of rows
        int n=obstacleGrid[0].size();   // no. of columns
        
        // set all values as -1 for dp
        vector<vector<int>> dp(m,vector<int>(n,-1));
        
        // return the possible paths
        return dfs(obstacleGrid,0,0,dp,m,n);   
    }
};
