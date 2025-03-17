class Solution {
public:
    int maxSum(vector<int>& nums) {

        if(nums.size() == 1) return nums[0];
        unordered_set<int> st;
        for(auto it: nums) {
            st.insert(it);
        }

        int maxValue = *max_element(nums.begin(), nums.end());

        int ans = INT_MIN;
        int sum = 0;
        bool isZero = false;
        for(auto it: st) {
            if(it == 0) isZero = true;
            if(it > 0) {
                sum += it;
            }
        }

        if(maxValue < 0 && isZero == true && sum == 0) {
            return maxValue;
        }

        if(maxValue < 0 && isZero == false && sum == 0) {
            return maxValue;
        }
        return sum;
    }
};