class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int cntbits = 0 ;
        while(num2){
            if(num2&1)cntbits++;
            num2 >>=1;
        }
        long long ans = 0;
        long long pw = 0;
        vector<int> setbits(32,0);
        while(num1)
        {
            if(num1&1)
            {
                setbits[pw]++;
            }
            pw++;
            num1 >>=1;
        }
        pw = pow(2,31);
        for(int i = 31; i>= 0; --i)
        {
            if(setbits[i] == 1 && cntbits > 0){
                ans += pw;
                cntbits--;
            }
            pw >>=1;
        }
        pw =1 ;
        for(int i = 0; i<32 ; ++i)
        {
            if(cntbits > 0 && setbits[i] != 1){
                ans += pw;
                cntbits--;
            }
            pw *=2;
        }
        return ans;
    }
};
