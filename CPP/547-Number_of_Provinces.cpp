class Solution {
    
    void dfs(int i,vector<vector<int>>& a,vector<int> &vis){
        vis[i]=1;
        int n=a.size();
        for(int j=0;j<n;j++){ //for each row traversing all elments
            if(vis[j]==0 && a[i][j]==1){ // if found 1 and that row is unvisited than go there to visit
                dfs(j,a,vis);
            }
            // in this manner we visit all elements connected to call i index and wiil neve be counted again because of vis
            //so only unique roads will call dfs 
        }
        return ;
    }
public:
    int findCircleNum(vector<vector<int>>& a) {
        int n= a.size();
        vector<int> vis(n,0);
        int ans=0;
        for(int i=0;i<n;i++){  // going to each line(row)
            if(vis[i]==0){
                dfs(i,a,vis);
                ans++;
            }
        }
        
        return ans;
    }
};