class Solution {
public:
    string largestPalindromic(string num) {
        // get the count of each character
        vector<int> cnt(10,0);
        for(char c:num){
            cnt[c-'0']++;
        }
        int ans=0;
        string str="";
        //greedily start from largest digit and check if it can be added in front as well as back and how many time
        for(int i=9;i>=1;i--){
            if(cnt[i]>1){
                ans+=2*(cnt[i]/2);
                int x=cnt[i]/2;
                while(x--)str+=char('0'+i);
                cnt[i]%=2;
            }
        }
        //handling zero explicitly because 000 or 00 is not valid palindrome number , i.e all are only 0
        if(cnt[0]>1){
            if(ans>0){
                ans+=2*(cnt[0]/2);
                int x=cnt[0]/2;
                while(x--)str+=char('0');
                cnt[0]%=2;
            }
        }
        bool f=false;

        // add middle digit
        for(int i=9;i>=0;i--){
            if(cnt[i]){str+=char('0'+i);f=true;ans++;break;}
        }
        int len=str.length();
        //make palindrome
        string tt=str.substr(0,len-(int)f);
        reverse(tt.begin(),tt.end());

        str+=tt;
        return str;
    }
};