class Solution {
public:
    void solve(int start, vector<int> &comb,  vector<vector<int>> &result, int n, int k) {
        if(comb.size() == k) {
            result.push_back(comb);
            return;
        }

        for(int i = start; i <=n; ++i) {
            comb.push_back(i);
            solve(i+1, comb, result, n, k);
            comb.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> comb;
        solve(1, comb, result, n, k);
        return result;
    }
};