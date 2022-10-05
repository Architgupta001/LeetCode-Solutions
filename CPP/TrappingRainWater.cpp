// Leetcode question 42. Trapping Rain Water 

#include <bits/stdc++.h>
using namespace std;

int trap(vector<int>& arr) {
    int n = arr.size();
    if(n < 2)
        return 0;
    int left[n], right[n], water = 0;
    left[0] = arr[0], right[n-1] = arr[n-1];
    
    for(int i=1; i<n; i++)
        left[i] = max(left[i-1], arr[i]);
    
    for(int i=n-2; i>=0; i--)
        right[i] = max(right[i+1], arr[i]);
    
    for(int i=0; i<n; i++)
        water += min(left[i], right[i]) - arr[i];
    
    return water;
}

int main()
{
    int n;
    cout<<"Enter number of buildings: ";
    cin>>n;
    vector<int> heights(n);
    cout<<"Enter heights of all buildings: ";
    for(int i=0; i<n; i++)
        cin>>heights[i];
    int ans = trap(heights);
    cout<<"Maximum water that can be trapped is: "<<ans<<endl;
    return 0;
}
