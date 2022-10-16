class Solution {
public:
    int bitwiseComplement(int n) {
        int m=n;
       int ignore=0;
        
        if(m==0){
            return 1;
        }
        
        while(m!=0){
            ignore=(ignore << 1) | 1;
            m = m >> 1;
        }
        
        int ans= (~n) & ignore;
        return ans;
    }
};