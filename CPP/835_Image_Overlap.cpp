//Problem description:
//https://leetcode.com/problems/image-overlap/
//Solution:

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<pair<int, int>> p1;
        vector<pair<int, int>> p2;
        for(int i=0; i<img1.size(); i++){
            for(int j=0; j<img1[0].size(); j++){
                if(img1[i][j]==1) p1.push_back({i,j});
                if(img2[i][j]==1) p2.push_back({i,j});
            }    
        }
        map<pair<int, int>, int> m;
        for(int i=0; i<p1.size(); i++){
            for(int j=0; j<p2.size(); j++){
                int x = p1[i].first - p2[j].first;
                int y = p1[i].second - p2[j].second;
                m[{x,y}]++;
            }
        }
        int mx = 0;
        for(auto x = m.begin(); x!=m.end(); x++ ){
            mx = max(mx,x->second); 
        }
        return mx;
    }
};

