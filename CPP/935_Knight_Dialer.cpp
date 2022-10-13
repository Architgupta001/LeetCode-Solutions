class Solution {
    int MOD = 1000000007;
public:
    
    int knightDialer(int n) {
        vector<long> curr(10, 1);
        vector<long> next = curr;
        for(int i=2; i<=n; i++)
        {
            next[0] = ((curr[4]%MOD)+(curr[6]%MOD))%MOD;
            next[1] = ((curr[8]%MOD)+(curr[6]%MOD))%MOD;
            next[2] = ((curr[9]%MOD)+(curr[7]%MOD))%MOD;
            next[3] = ((curr[4]%MOD)+(curr[8]%MOD))%MOD;
            next[4] = ((curr[3]%MOD)+(curr[9]%MOD)+(curr[0]%MOD))%MOD;
            next[5] = 0;
            next[6] = ((curr[1]%MOD)+(curr[7]%MOD)+(curr[0]%MOD))%MOD;
            next[7] = ((curr[2]%MOD)+(curr[6]%MOD))%MOD;
            next[8] = ((curr[1]%MOD)+(curr[3]%MOD))%MOD;
            next[9] = ((curr[4]%MOD)+(curr[2]%MOD))%MOD;
            curr = next;
        }
        int ans = 0;
        for(int i=0; i<10; i++)
            ans=((ans+next[i])%MOD);
        return ans;
    }
};
