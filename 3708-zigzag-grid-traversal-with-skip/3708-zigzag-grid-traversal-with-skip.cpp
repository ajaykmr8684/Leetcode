class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> result;

        int i = 0;
        int j = 0;

        while(i < n)
        {
            if(i % 2 == 0)
            {
                for(int x = 0; x < grid[0].size(); x++)
                {
                    if(x%2 == 0) result.push_back(grid[i][x]);
                }
            }
            else
            {
                for(int x = grid[0].size() - 1; x >= 0; x--)
                {
                    if(x%2 == 1)result.push_back(grid[i][x]);
                    
                }
            }

            i++;
        }
        
        return result;
    }
};