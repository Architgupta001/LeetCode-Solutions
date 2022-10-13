class Solution {
public:
    void BFS(vector<bool>&visited, vector<vector<int>>& rooms, int source){
        queue<int>q;
        q.push(source);
        visited[source]=true;
        while(!q.empty())
        {
            int front=q.front();
            q.pop();
            for(auto neighbour : rooms[front]){
                if(!visited[neighbour]){
                    visited[neighbour]=true;
                    q.push(neighbour);
                }
            }
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool>visited(rooms.size(), false);
        
        BFS(visited, rooms, 0);
       
        for(auto it : visited){
            if(it!=1){
                return false;
            }
        }
        return true;
    }
};