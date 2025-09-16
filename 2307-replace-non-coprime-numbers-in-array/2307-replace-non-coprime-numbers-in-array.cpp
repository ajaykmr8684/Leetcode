class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> result;

        for(int i = 0; i < nums.size(); ++i) {
            while(!result.empty()) {
                int curr = nums[i];
                int back = result.back();
                int GCD = gcd(curr, back);

                if(GCD == 1) {
                    break;
                }

                result.pop_back();
                int LCM = back / GCD * curr;
                nums[i] = LCM;
            }
            result.push_back(nums[i]);
        }

        return result;
    }
};