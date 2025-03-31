class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        //I think it is just to find smallest to the left
        int n = cost.size();
        vector<int> result(n, 0);
        result[0] = cost[0];
        int currentMin = cost[0];    
        for(int i = 1; i < n; ++i) {
            if(currentMin > cost[i]) {
                currentMin = cost[i];
            }
            result[i] = currentMin;
        }

        return result;
    }
};