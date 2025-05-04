class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& doms) {
        int n = doms.size();
        map<pair<int, int>, int> mp;
        int result = 0;
        for(int i = 0; i < n; ++i) {
            pair<int, int> temp = {min(doms[i][0], doms[i][1]), max(doms[i][0], doms[i][1])};
            if(mp.find(temp) != mp.end()) {
                result += mp[temp];
            }

            mp[temp]++;
        }

        return result;
    }
};