class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> uset;

        for(int i = 0; i < 9; ++i) {
            for(int j = 0; j < 9; ++j) {

                if(board[i][j] != '.') {
                    string row = "ROW_" + to_string(i) + board[i][j];
                    string col = "COL_" + to_string(j) + board[i][j];
                    string box = "BOX_" + to_string((i/3)*3 + j/3) + board[i][j];

                    if(uset.find(row) != uset.end() || uset.find(col) != uset.end() || uset.find(box) != uset.end()) return false;
                    uset.insert(row);
                    uset.insert(col);
                    uset.insert(box);
                }
            }
        }

        return true;
    }
};