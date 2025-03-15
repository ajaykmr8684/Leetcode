class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> st;

        int i = 0;
        int j = 0;

        while(j < n) {
            if(abs(j- i) <= k) {
                if(st.count(nums[j])){
                    return true;
                }
                st.insert(nums[j]);
                j++;
            }
            else
            {
                st.erase(nums[i]);
                i++;
            }
        }

        return false;
    }
};