class Solution {
public:
    int N;
    vector<vector<string>> result;
    unordered_set<int> cols;
    unordered_set<int> diag;
    unordered_set<int> antiDiag;

    void solve(vector<string> &board, int row) {
        if(row >= N) {
            result.push_back(board);
            return;
        }

        for(int col = 0; col < N; ++col) {
            int diags = col + row;
            int antiDiags = row - col;
            if(cols.find(col) != cols.end() || diag.find(diags) != diag.end() || antiDiag.find(antiDiags) != antiDiag.end()) {
                continue;
            }

            diag.insert(diags);
            antiDiag.insert(antiDiags);
            cols.insert(col);
            board[row][col] = 'Q';
            solve(board, row+1);
            board[row][col] = '.';
            diag.erase(diags);
            antiDiag.erase(antiDiags);
            cols.erase(col);
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        N = n;
        vector<string> board (n, string(n, '.'));
        solve(board, 0);
        return result;
    }
};