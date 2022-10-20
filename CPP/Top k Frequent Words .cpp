
class cmp{
    public:
    bool operator()(pair<int,string> a, pair<int,string> b) const{
        if(a.first < b.first) return true;
        else if(a.first == b.first && a.second>b.second) return true;
        return false;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> ump;
        for(auto &w : words) ump[w]++;
        
        priority_queue<pair<int,string>,vector<pair<int,string>>,cmp> pq;
        for(auto &m : ump) pq.push({m.second,m.first});
        
        vector<string> vec;
        while(k--){
            vec.push_back(pq.top().second);
            pq.pop();
        }
        return vec;
    }
};