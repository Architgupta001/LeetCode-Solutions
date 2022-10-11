class Solution
{
public:
    // Prints sums of all subsets of arr[l..r]
    void subsetSumsHelper(vector<int>& arr, int l, int r, vector<int> &v,
                    int sum=0)
    {
        // Print current subset
        if (l > r)
        {
            v.push_back(sum);
            return;
        }
    
        // Subset including arr[l]
        subsetSumsHelper(arr, l+1, r, v, sum+arr[l]);
    
        // Subset excluding arr[l]
        subsetSumsHelper(arr, l+1, r, v, sum);
    }
    
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> v;
        subsetSumsHelper(arr, 0, N-1, v);
        return v;
    }
};