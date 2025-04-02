class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> preMax(nums.size());
        vector<int> sufMax(nums.size());

        //Fill preMax
        int maxi = INT_MIN;
        for(int i = 1; i < n; ++i) {
            preMax[i] = max(preMax[i-1], nums[i-1]);
        }

        //Fill sufMax
        maxi = INT_MIN;
        for(int i = n-2; i >= 0; --i) {
            sufMax[i] = max(sufMax[i+1], nums[i+1]);
        }
        
        long long ans = 0;
        for(int i = 0; i < n; ++i) {
            long long eval = (long long )(preMax[i] - nums[i]) * sufMax[i];
            ans = max(ans, eval);
        }

        return ans;

    }
};