#include <bits/stdc++.h>

using namespace std;


     int singleNumber(vector<int>& nums) {
     //fuction to calculate unique number using std::map
     map<int,int> m;
     int k=0;
     for(int i=0;i<nums.size();i++){
         m[nums[i]]++;
     }
     for(auto p:m){
         if(p.second==1)
         k=p.first;
     }
     return k;
    }
    //main function 
    int main()
{ vector<int> v;int n,x;
cout<<"enter number of elements to be entered in vector";
cin>>n;
for(int i=0;i<n;i++){
    cin>>x;
    v.push_back(x);
}
//calling of function
cout<<singleNumber(v);
    return 0;
}
