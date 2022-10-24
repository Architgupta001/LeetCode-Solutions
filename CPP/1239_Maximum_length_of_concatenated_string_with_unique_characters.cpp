class Solution {
public:
    
    int ans = 0;    
    bool is_unique(string& str)
    {
        vector<int> mp(26, 0);
        for(int i = 0; i < str.size(); i++)
        {
            mp[str[i] - 'a']++;
            if(mp[str[i] - 'a'] > 1)
                return false;
        }
        return true;
    }
    
    void backtrack(vector<string>& arr, int i, int n, string curr)
    {
        if(is_unique(curr) == false)
            return;
        if(i == n)
        {
            if(curr.size() > ans)
            {
                int size = curr.size();
                ans = max(ans, size);
            }
            
            return;
        }
        backtrack(arr, i + 1, n, curr + arr[i]);
        backtrack(arr, i + 1, n, curr);
    }
    
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        backtrack(arr, 0, n, "");
        return ans;
    }
};