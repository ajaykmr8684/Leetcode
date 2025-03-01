class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        for(int i = 0; i < nums.size() - 1; ++i) {
            if(nums[i] == nums[i+1]) {
                nums[i] = nums[i] * 2;
                nums[i+1] = 0;
            }
        }
        
        int i = 0;
        int j = 0;
        
        while( i < nums.size()) {
            if(nums[i] != 0) {
                swap(nums[i], nums[j]);
                i++;
                j++;
            }
            else i++;
        }
        return nums;
    }
};