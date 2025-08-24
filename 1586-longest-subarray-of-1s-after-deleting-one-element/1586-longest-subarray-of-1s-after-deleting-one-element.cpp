class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i = 0, j = 0;
        int zeroCount = 0;
        int result = INT_MIN;
        while(j < nums.size()) {
            if(nums[j] == 0) zeroCount++;
            while(zeroCount > 1) {
                if(nums[i] == 0) zeroCount--;
                i++;
            }

            result = max(result, j - i);
            j++;
        }

        return result;
    }
};