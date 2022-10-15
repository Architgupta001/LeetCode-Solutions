class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
   for (int first = 0; first < nums.size(); first++){
			//For every first ...
            for (int second = first + 1; second < nums.size(); second++){
				//... and second, ...
                if (nums[first] + nums[second] == target){
				//... if nums[first] + nums[second] == target then return {first, second}.
                    return {first, second};
                }
            }
        }
		//If there is no solution return an empty vector.
        return {};
    }
};
