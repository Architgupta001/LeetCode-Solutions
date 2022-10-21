class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        temp={}
        for i in range(len(nums)):
            if nums[i] in temp.keys():
                if abs(temp[nums[i]]-i)<=k:
                    return True
                else:
                    temp[nums[i]]=i
            else:
                temp[nums[i]]=i
        else:
            return False