class Solution {
public:
    string solve(int len, string s, int index, unordered_set<string> &uset) {
        if(index == len)
        {
            if(uset.find(s) == uset.end()) return s;
            return "";
        }

         // Try '0' first
        s[index] = '0';
        string res = solve(len, s, index + 1, uset);
        if (!res.empty()) return res; // If a valid result is found, return it

        // Try '1' if '0' didn't work
        s[index] = '1';
        return solve(len, s, index + 1, uset);
    }

    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string> uset(begin(nums), end(nums));
        int bitlen = nums[0].size();
        string curr(bitlen, '0');
        return solve(bitlen, curr, 0, uset);
    }
};