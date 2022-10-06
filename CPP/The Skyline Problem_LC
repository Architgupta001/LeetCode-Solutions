class Solution {
public:
   vector<vector<int>> getSkyline(vector<vector<int>>& b) {
        vector<vector<int>>v;
        int n=b.size(),i=0;
        priority_queue<vector<int>>pq;
        vector<int>pos;
        for(auto it:b){
            pos.push_back(it[0]);
            pos.push_back(it[1]);
        }
        sort(pos.begin(),pos.end());
        
        int x,h,sz=pos.size(),j=0;
        while(i<sz){
            while(j<n&&b[j][0]<=pos[i]&&b[j][1]>=pos[i]){
                pq.push({b[j][2],b[j][1]});
                j++;
            }
            while(pq.size()&&pq.top()[1]<=pos[i]){
                pq.pop();
            }
            if(pq.size()){
               if(v.empty()||v[v.size()-1][1]!=pq.top()[0]){
                v.push_back({pos[i],(int)pq.top()[0]});
              } 
            }
            else{
                if(v.empty()||v[v.size()-1][1]!=0)
                v.push_back({pos[i],0});
            }
            i++;
        }
        return v;
    }
};
