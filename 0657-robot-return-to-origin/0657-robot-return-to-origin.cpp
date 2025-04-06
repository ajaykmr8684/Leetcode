class Solution {
public:
    bool judgeCircle(string moves) {
        int rowCount = 0;
        int colCount = 0;
        for(int i = 0; i < moves.length(); ++i) {
            if(moves[i] == 'L' || moves[i] == 'R') {
                if(moves[i] == 'L') rowCount--;
                else rowCount++;
            }
            else {
                if(moves[i] == 'D') {
                    colCount--;
                }
                else colCount++;
            }
        }

        return (rowCount == 0 && colCount == 0);
    }
};