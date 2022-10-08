class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> v;
        double ans;
        for (auto i : nums1)
        {
            v.push_back(i);
        }
        for (auto i : nums2)
        {
            v.push_back(i);
        }
        sort(v.begin(), v.end());
        int n = v.size();
        if (n % 2 != 0)
        {
            return v[n / 2];
        }
        else
        {
            int a = v[n / 2];
            int b = v[(n / 2) - 1];
            ans = (a + b) / 2.0;
        }
        return ans;
    }
};