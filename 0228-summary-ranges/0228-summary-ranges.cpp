class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        
        vector<string> result;
        if(n == 0) return result;
        int start = nums[0];
        for(int i = 1; i <= n; ++i) {
            if(i == n || nums[i] != nums[i-1]+1) {
                string temp = to_string(start) + "->" + to_string(nums[i-1]);
                if(nums[i-1] == start) result.push_back(to_string(start));
                else result.push_back(temp);
                if(i < n) start = nums[i];
            }
        }
        return result;
    }
};