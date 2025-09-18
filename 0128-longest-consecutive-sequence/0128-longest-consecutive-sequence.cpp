class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> values;
        int ans = 0;

        for(auto it: nums)
        {
            values[it] = 1;
        }

        for(auto it: nums)
        {
            if(values.find(it-1) != values.end())
            {
                continue;
            }
            else
            {
                int temp = it;
                int count = 0;
                while(values.find(temp) != values.end())
                {
                    count++;
                    temp++;
                }
                ans = max(ans, count );
            }
        }

        return ans;

    }
};