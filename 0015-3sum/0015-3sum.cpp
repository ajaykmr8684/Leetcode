class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size() < 3) return {};
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); ++i) {

            if(i > 0 && nums[i] == nums[i-1]) continue;
            int target = -nums[i];
            cout << target;

            int l = i +1;
            int r = nums.size() - 1;

            while(l < r) {
                if(nums[l] + nums[r] > target) r--;
                else if(nums[l] + nums[r] < target) l++;
                else {
                    while(l < r && nums[l] == nums[l+1]) l++;
                    while(l < r && nums[r] == nums[r-1]) r--;
                    ans.push_back({-target, nums[l], nums[r]});
                                    l++;
                r--;
                }
            }
        }

        return ans;
    }
};