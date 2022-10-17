/* Question Link: https://leetcode.com/problems/rotting-oranges/ */
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        int vis[n][m];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                else
                {
                    vis[i][j]=0;
                }
            }
        }
        int delRow[] = {-1,0,+1,0};
        int delCol[] = {0,+1,0,-1};
        int time=0;
        while(!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            time = max(t,time);
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nrow = r + delRow[i];
                int ncol = c + delCol[i];
                if((nrow>=0 && nrow<n) && (ncol>=0 && ncol<m)  && vis[nrow][ncol]!=2 && grid[nrow][ncol]==1)
                {
                    q.push({{nrow,ncol},t+1});
                    vis[nrow][ncol]=2;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 && vis[i][j]!=2)
                {
                    return -1;
                }
            }
        }
        return time;
    }
};