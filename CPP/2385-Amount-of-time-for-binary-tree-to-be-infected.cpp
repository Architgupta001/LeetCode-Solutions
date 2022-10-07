class Solution {
public:
    int n=0;
    void dfs(TreeNode* root,TreeNode* par,vector<vector<int>> &adj){
        n++;
        if(par){
            adj[root->val].push_back(par->val);
        }
        if(root->left){
            adj[root->val].push_back(root->left->val);
            dfs(root->left,root,adj);
        }
        if(root->right){
            adj[root->val].push_back(root->right->val);
            dfs(root->right,root,adj);
        }
    }
    
    void dfs1(int s,vector<vector<int>> &adj,vector<bool> &vis,vector<int> &dis){
        vis[s]=true;
        for(int v:adj[s]){
            if(!vis[v]){
                dis[v]=1+dis[s];
                dfs1(v,adj,vis,dis);
            }
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        //create undirected graph using the given tree
        vector<vector<int>> adj(100001);
        dfs(root,NULL,adj);

        //find distance of all nodes from start node
        vector<int> dis(100001,INT_MAX);
        dis[start]=0;
        vector<bool> vis(100001,false);
        dfs1(start,adj,vis,dis);
        int ans=0;

        //find maximum distance out of all the nodes present from the start node
        for(int i=1;i<=100000;i++){
            if(dis[i]!=INT_MAX)ans=max(ans,dis[i]);
        }
        return ans;
    }
};