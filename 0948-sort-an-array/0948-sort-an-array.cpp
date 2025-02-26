class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> ans;
        int mini = INT_MAX;
        int maxi = INT_MIN;

        for(int i = 0; i < nums.size(); ++i) {
            maxi = max(maxi, nums[i]);
            mini = min(mini, nums[i]);
        }

        //Save it in a map
        unordered_map<int, int> umap;

        for(int i = 0; i < nums.size(); ++i) {
            umap[nums[i]]++;
        }

        for(int i = mini; i <= maxi; ++i) {
            int count = umap[i];
            for(int k = 0; k < count; ++k) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};