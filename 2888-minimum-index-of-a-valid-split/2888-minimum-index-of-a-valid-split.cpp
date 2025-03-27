class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp1, mp2;
        for(auto it: nums) mp2[it]++;

        for(int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            mp1[num]++;
            mp2[num]--;

            int n1 =  i + 1;
            int n2 = n - i - 1;

            if(mp1[num]*2 > n1 && mp2[num]*2 > n2) return i;
        }

        return -1;
    }
};