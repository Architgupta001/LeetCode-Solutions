/*  This problem is an applicaiton of binary search concept 

The mountain array is an array that contains first few elements in increasing order and then decreasing order
Ex - 1 4 5 3 2

NOTE - The solution template below is of that on leetcode side
To run on local machine you need to add header file (#include<bits/stdc++.h>) and create the main function

*/



class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
        int start = 0;
        int end = arr.size() - 1;
        int mid = start + (end - start)/2;
        
        //Note we are not providing equal to sign here because it will repeat the condition of checking elements.
        
        while(start < end){
            
            //Consider this for the increasing side of mountain array
            
            if(arr[mid] < arr[mid+1]){
                start = mid + 1;
            }
            
            //Consider this for peak as well as decreasing side of mountain array
            
            else{
                
                end = mid;
            }
            //Reason for setting end to mid is we are including the case of getting peak element here , so doing end = mid - 1 will skip the peak and we will run into error.
            
            mid = start + (end - start)/2;
        }
        return start;
    }
};