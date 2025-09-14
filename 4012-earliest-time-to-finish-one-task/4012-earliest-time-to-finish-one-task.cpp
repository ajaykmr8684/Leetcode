class Solution {
public:
    int ans = INT_MAX;
    int earliestTime(vector<vector<int>>& tasks) {
        for(int i = 0; i < tasks.size(); ++i) {
            int startTime = tasks[i][0];
            int endTime = tasks[i][1];
            ans = min(ans, startTime+endTime);
        }

        return ans;
    }
};