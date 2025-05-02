class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& b) {
        
        vector<int> rowMin(n + 1, INT_MAX), rowMax(n + 1, INT_MIN);
        vector<int> colMin(n + 1, INT_MAX), colMax(n + 1, INT_MIN);

        
        for (auto& p : b) {
            int x = p[0], y = p[1];
            rowMin[x] = min(rowMin[x], y);
            rowMax[x] = max(rowMax[x], y);
            colMin[y] = min(colMin[y], x);
            colMax[y] = max(colMax[y], x);
        }
        
        int res = 0;
        
        for (auto& p : b) {
            int x = p[0], y = p[1];
            
            bool covered = (y > rowMin[x] && y < rowMax[x]) &&  
                           (x > colMin[y] && x < colMax[y]);    
            
            if (covered) {
                res++;
            }
        }
        
        return res;
    }
};