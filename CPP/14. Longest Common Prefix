class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int L = 0;
        for(int i=0;i<strs[0].length();i++){
            int ok = 1;
            for(auto& s:strs){
                if(L>=s.length() or s[L]!=strs[0][L]){
                    ok = 0;
                    break;
                }
            }
            if(ok){
                L++;
            }
            else{
                break;
            }
        }
        return strs[0].substr(0,L);
    }
};
