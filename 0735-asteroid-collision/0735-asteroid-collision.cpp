class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for(auto it: asteroids) {
            if(it < 0) {
                while(!st.empty() && st.top() < abs(it) && st.top() > 0) {
                    st.pop();
                } 

                if(st.empty() || st.top() < 0) {
                    st.push(it);
                }
                else if(st.top() == abs(it)) st.pop();

            }
            else {
                st.push(it);
            }
        }
        if(st.empty()) return {};
        vector<int> ans(st.size());
        int i = ans.size() - 1;
        while(!st.empty()) {
            ans[i] = st.top();
            st.pop();
            i--;
        }

        return ans;
    }
};