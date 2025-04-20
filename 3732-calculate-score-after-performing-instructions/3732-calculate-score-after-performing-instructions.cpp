class Solution {
public:
    long long calculateScore(vector<string>& instructions, vector<int>& values) {
         int n = values.size();
        long long score = 0;
        vector<bool> visited(n, false);
       
        int i = 0;
        while(i >=0  && i < n &&  !visited[i]) {
            visited[i] = true;
            if(instructions[i] == "jump") {
                i = i + values[i];
            }
            else if(instructions[i] == "add"){
                score += values[i];
                i = i + 1;
            }
        }

        return score;
    }
};