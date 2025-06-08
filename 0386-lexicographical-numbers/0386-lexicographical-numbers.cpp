class Solution {
public:
    void solve(int i, int n, vector<int> &result) {
        if(i > n) return;
        result.push_back(i);

        for(int j = 0; j <= 9; ++j) {
            int newNum = (i * 10) + j;
            if(newNum > n) return;
            solve(newNum, n, result);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        for(int i = 1; i <= 9; ++i) {
            solve(i, n, result);
        }
        return result;
    }
};