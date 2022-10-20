#include<iostream>
#include<vector>

using namespace std;

int firstOcc(vector<int>& nums,int n, int target){
            int ans=-1;
            int s=0;
            int e=n-1;
            int mid=s+(e-s)/2;
            while(s<=e){
                if(nums[mid]==target){
                    ans=mid;
                    e=mid-1;
                }
                else if(target>nums[mid]){
                    s=mid+1;
                }
                else{
                    e=mid-1;
                }
                mid=s+(e-s)/2;
        }
        return ans;
    }

 int lastOcc(vector<int>& nums,int n, int target){
            int ans=-1;
            int s=0;
            int e=n-1;
            int mid=s+(e-s)/2;
            while(s<=e){
                if(nums[mid]==target){
                    ans=mid;
                    s=mid+1;
                }
                else if(target>nums[mid]){
                    s=mid+1;
                }
                else{
                    e=mid-1;
                }
                mid=s+(e-s)/2;
        }
        return ans;
    }

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> sol;
        int n=nums.size();
        sol.push_back(firstOcc(nums, n, target));
        sol.push_back(lastOcc(nums, n, target));
        return sol;
   
    }
};


int main(){
vector<int> a={2,3,4,5,3,6,8};
int key=3;

Solution s1;

vector<int> v;

v = s1.searchRange(a, key);
cout<<v;

return 0;
}
