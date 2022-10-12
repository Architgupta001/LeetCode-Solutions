class Solution {
public:
    int next_clr;
    void dfs(int v, int clr, vector<int> adj[], vector<int> &color)
    {
        color[v] = clr;
        if(clr+1 == 5)   //rotating colors cannot use mod as 4%4 = 0 (not a color) so when clr+1 = 5 just make it 1
            next_clr = 1;
        else
            next_clr = clr+1;  
        
        for(auto u: adj[v])
        {
            if(color[u] == 0)                //if color not assigned then assign the next_clr
                dfs(u, next_clr, adj, color);
            else if(color[v] == color[u])     //u is already assigned the same color so change the current node color to next_clr
                dfs(v, next_clr, adj, color);
        }
    }
    
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) 
    {
        vector<int> color(n, 0);
        vector<int> adj[n];
        
        for(auto i: paths)
        {
            adj[i[0]-1].push_back(i[1]-1); //0-indexed
            adj[i[1]-1].push_back(i[0]-1);
        }
        
        for(int i=0; i<n; i++)
            if(color[i] == 0)
                dfs(i, 1, adj, color);
        
        return color;
    }
};
