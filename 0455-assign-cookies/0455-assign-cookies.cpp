class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(), s.end());
        sort(g.begin(), g.end());

        int i = 0, j = 0;
        int ans = 0;

        while(i < g.size() && j < s.size()) {
            if(g[i] <= s[j]) {
                ans++;
                i++;
                j++;
            }
            else j++;
        }

        return ans;
    }
};