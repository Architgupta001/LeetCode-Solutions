/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int peakElement(MountainArray &mountainArr, int size){
        int start=0;
        int end=size-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            int middle=mountainArr.get(mid);
            if(mid>0 && mid<size-1){
                int prev=mountainArr.get(mid-1);
                int next=mountainArr.get(mid+1);
                if(middle>prev && middle>next)
                    return mid;
                else if(prev>middle)
                    end=mid-1;
                else if(next>middle)
                    start=mid+1;
            }
            else if(mid==0){
                if(mountainArr.get(0)>mountainArr.get(1))
                    return 0;
                else
                    return 1;
            }
            else if(mid==size-1){
                if(mountainArr.get(size-1)>mountainArr.get(size-2))
                    return size-1;
                else
                    return size-2;
            }
        }
        return -1;
    }
    int ascBs(MountainArray &mountainArr, int start, int end, int target){
        while(start<=end){
            int mid=start+(end-start)/2;
            int middle=mountainArr.get(mid);
            if(middle==target)
                return mid;
            else if(middle<target)
                start=mid+1;
            else if(middle>target)
                end=mid-1;
        }
        return -1;
    }
    int desBs(MountainArray &mountainArr, int start, int end, int target){
        while(start<=end){
            int mid=start+(end-start)/2;
            int middle=mountainArr.get(mid);
            if(middle==target)
                return mid;
            else if(middle<target)
                end=mid-1;
            else if(middle>target)
                start=mid+1;
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int size=mountainArr.length();
        int peak=peakElement(mountainArr, size);
        int left=ascBs(mountainArr, 0, peak, target);
        int right=desBs(mountainArr, peak+1, size-1, target);
        if(left==-1 && right==-1)
            return -1;
        else if(left!=-1 && right==-1)
            return left;
        else if(left==-1 && right!=-1)
            return right;
        else
            return min(left, right);
        return 0;
    }
};
