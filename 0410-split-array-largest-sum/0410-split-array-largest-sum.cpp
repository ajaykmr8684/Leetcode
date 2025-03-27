class Solution {
public:
    bool canSplit(vector<int> &nums, int mid, int k) {
        int ways = 1;
        int sum = 0;
        for(auto &it: nums) {
            if(it + sum > mid) {
                ways++;
                sum = it;
            } 
            else sum += it;
        }

        return ways <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        int l = *max_element(nums.begin(), nums.end());
        int r = accumulate(nums.begin(), nums.end(), 0);

        while(l <= r) {
            int mid = l + (r - l) / 2;

            if(canSplit(nums, mid, k)) {
                r = mid - 1;
            }
            else l = mid + 1;
        }

        return l;
    }
};