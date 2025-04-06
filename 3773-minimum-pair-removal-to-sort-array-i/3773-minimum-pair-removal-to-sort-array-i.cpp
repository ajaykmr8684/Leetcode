class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        if(is_sorted(nums.begin(), nums.end())){
            return 0;
        }
        int ans = 0;
        while(!is_sorted(nums.begin(), nums.end())){
            int minIndex = 0;
            int minSum = nums[0] + nums[1];
            
            for (int i = 1; i < nums.size() - 1; i++) {
                int sum = nums[i] + nums[i + 1];
                if (sum < minSum) {
                    minSum = sum;
                    minIndex = i;
                }
            }
            
            nums[minIndex] = minSum;
            nums.erase(nums.begin() + minIndex + 1);
            ans++;
        }

        return ans;
    }
};