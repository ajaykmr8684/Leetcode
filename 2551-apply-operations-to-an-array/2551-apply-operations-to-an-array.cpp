class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int j = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if( i +1 < nums.size() && nums[i] == nums[i+1]) {
                nums[i] = nums[i] * 2;
                nums[i+1] = 0;
            }
            if(nums[i] != 0) {
                if(i != j) swap(nums[i], nums[j]);
                j++;
            }
        }
        
        return nums;
    }
};