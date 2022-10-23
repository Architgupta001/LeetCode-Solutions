class Solution {
public:
  vector<vector<long long>> splitPainting(vector<vector<int>> &s) {
    int n = 1e6 + 1;
    map<int, long long> ok;
    for (auto x : s) {
      int start = x[0], end = x[1], val = x[2];
      ok[start] += val;
      ok[end] -= val;
    }
    long long tmp = 0;
    int last = -1;
    vector<vector<long long>> ans;
    for (auto [k, v] : ok) {
      if (last != -1 and tmp) {
        ans.push_back({last, k, tmp});
      }
      last = k;
      tmp += v;
    }
    return ans;
  }
};
