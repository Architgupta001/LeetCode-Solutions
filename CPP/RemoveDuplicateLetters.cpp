// Leetcode question 316. Remove Duplicate Letters 

class Solution {
public:
    string removeDuplicateLetters(string s) {
        //cnt for storing frequency of characters
        //vis for marking visited characters
        vector<int> cnt(26,0), vis(26,0);
        string ans = "";
        int n = s.size();
        
        for(int i=0; i<n; i++)
            cnt[s[i]-'a']++;
        
        for(int i=0; i<n; i++)
        {
            //decrease cnt of current character
            cnt[s[i]-'a']--;
            //if character is not already in answer
            if(!vis[s[i]-'a'])
            {
                //last character > s[i] and its count > 0
                while(ans.size() > 0 && ans.back() > s[i] && cnt[ans.back()-'a'] > 0)
                {
                    //marking letter visited
                    vis[ans.back()-'a'] = 0;
                    ans.pop_back();
                }
                //add s[i] in ans and mark it visited
                ans += s[i];
                vis[s[i]-'a'] = 1;
            }
        }
        
        return ans;
    }
};