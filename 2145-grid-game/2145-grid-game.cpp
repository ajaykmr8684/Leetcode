class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long firstRowRemainingSum = accumulate(begin(grid[0]), end(grid[0]), 0LL);

        long long secondRowRemSum = 0;

        long long minimizedR2Sum = LONG_LONG_MAX;

        for(int r1Col = 0; r1Col < grid[0].size(); ++r1Col)
        {
            firstRowRemainingSum -= grid[0][r1Col];
            long long bestofR2 = max(firstRowRemainingSum, secondRowRemSum);
            minimizedR2Sum = min(minimizedR2Sum, bestofR2);
            secondRowRemSum += grid[1][r1Col];
        }

        return minimizedR2Sum;
    }
};