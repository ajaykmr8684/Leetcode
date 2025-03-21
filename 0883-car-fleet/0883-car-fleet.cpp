class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, float>>time(n);

        for(int i = 0; i < n; ++i) {
            time.push_back({position[i], float(target - position[i])/speed[i]});
        }

        sort(time.begin(), time.end());

        stack<float> st;
        for(auto it: time) {
            float tm = it.second;
            while(st.size() && st.top() <= tm) {
                st.pop();
            }

            st.push(tm);
        }

        return st.size();
    }
};