class Solution {
public:
    int countSubsets(int idx, int sumOr, vector<int> nums, int maxOr){
        
        if(idx >= nums.size()) {
            if(sumOr == maxOr) {
                return 1;
            }
            return 0;
        } 

        //Take
        int take = countSubsets(idx+1, sumOr | nums[idx], nums, maxOr);

        // Not take
        int not_take = countSubsets(idx+1, sumOr, nums, maxOr);

        return take + not_take;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;
        for(auto it: nums) {
            maxOr |= it;
        }

        return countSubsets(0, 0, nums, maxOr);
    }
};