class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size(), 1);
        vector<int> suffix(nums.size(), 1);
        vector<int> ans;
        int n = nums.size();

        prefix[0] = 1;
        suffix[n -1] = 1;

        for(int i = 1; i < nums.size(); ++i)
        {
           prefix[i] = prefix[i-1] * nums[i-1];
        }

        for(int i = n - 2; i >= 0; --i)
        {
           suffix[i] = suffix[i+1] * nums[i+1];
        }

        for(int i = 0; i < prefix.size(); ++i)
        {
            cout << prefix[i] << endl;
        }

        for(int i = 0; i < prefix.size(); ++i)
        {
            cout << suffix[i] << endl;
        }

        for(int i = 0; i < nums.size(); ++i)
        {
            ans.push_back(prefix[i] * suffix[i]);
        }
        return ans;
    }
};