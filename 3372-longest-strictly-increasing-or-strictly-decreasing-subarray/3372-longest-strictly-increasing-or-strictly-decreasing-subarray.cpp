class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int increasingNum = 1;
        int decreasingNum = 1;
        int maxLen = 1;

        for(int i = 1; i < nums.size(); ++i)
        {
            if(nums[i] > nums[i-1])
            {
                increasingNum++;
                decreasingNum = 1;
            }
            else if(nums[i] < nums[i-1])
            {
                decreasingNum++;
                increasingNum = 1;
            }
            else
            {
                decreasingNum = 1;
                increasingNum = 1;
            }

            maxLen = max(maxLen, max(decreasingNum, increasingNum));
        }

        return maxLen;
    }
};