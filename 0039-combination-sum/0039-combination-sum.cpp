class Solution {
public:
    int n;

    void solve(vector<int>& comb, int i, vector<int>& candidates, int target, vector<vector<int>> &result) {
        if(i == n || target < 0) {
            return;
        }

        if(target == 0) {
            result.push_back(comb);
            return;
        }

        comb.push_back(candidates[i]);
        solve(comb, i, candidates, target - candidates[i], result);
        comb.pop_back();

        solve(comb, i+1, candidates, target, result);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n = candidates.size();  
        vector<int> comb;
        vector<vector<int>> result;
        solve(comb, 0, candidates, target, result);
        return result;
    }
};
