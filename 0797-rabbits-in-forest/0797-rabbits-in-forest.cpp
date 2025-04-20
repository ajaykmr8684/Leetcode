class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> mp;

        for(auto it: answers) mp[it]++;
        int result = 0;

        for(auto it: mp) {
            int x =it.first;
            int count = it.second;

            int grpSize = x+1;
            int groups = ceil((double) count/grpSize);
            result += (groups * grpSize);
        }

        return result;
    }
};