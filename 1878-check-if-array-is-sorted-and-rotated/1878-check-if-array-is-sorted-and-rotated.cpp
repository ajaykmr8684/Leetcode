class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int peaks = 0;

        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] > nums[(i+ 1) % n]) peaks++;
        }
        cout << peaks;

        if(peaks <= 1) return true;

        return false;

    }
};