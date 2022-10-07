// Leetcode 1971 : Find if path exists in graph

class Solution {
public:
    bool dfs(vector<int> adj[],vector<bool> &visited,int source,int destination){
        if(source == destination)
            return true;
        visited[source] = true;
        for(auto i : adj[source]){
            if(!visited[i])
                if(dfs(adj,visited,i,destination))
                    return true;
        }
        return false;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<bool> visited(n,false);
        vector<int> adj[n];
        for(auto& edge : edges){
            int u = edge[0],v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return dfs(adj,visited,source,destination);
    }
};