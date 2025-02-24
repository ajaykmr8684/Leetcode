class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap;
        vector<int> ans(2, 0);

        for(int i = 0; i < nums.size(); ++i) {
            if(umap.find(target- nums[i]) != umap.end()) {
                ans[0] = i;
                ans[1] = umap[target-nums[i]];
            }

            umap[nums[i]] = i;
        }

        return ans;
    }
};