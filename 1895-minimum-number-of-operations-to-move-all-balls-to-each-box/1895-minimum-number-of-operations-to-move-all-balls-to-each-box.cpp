class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> result;
        unordered_set<int> balls;
        for(int i = 0; i < boxes.length(); ++i)
        {
            if(boxes[i] == '1') balls.insert(i);
        }

        for(int i = 0; i < boxes.length(); ++i)
        {
            int movement = 0;
            for(auto it: balls)
            {
                int ball_idx = i;
                movement += abs(it - i);
            }

            result.push_back(movement);
        }
    return result;
    }
};