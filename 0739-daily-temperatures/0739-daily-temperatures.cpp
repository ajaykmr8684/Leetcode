class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int> ans(n, 0);
        stack<pair<int, int>> st;
        ans[n-1] = 0;
        st.push({temp[n-1], n-1});
        for(int i = n-2; i >=0; --i) {
            while(!st.empty() && st.top().first <= temp[i]) {
                st.pop();
            }
            if(st.empty()) {
                ans[i] = 0;
            }
            else {
                int indx = st.top().second;
                ans[i] = indx - i;
            } 
            st.push({temp[i], i});
        }

        return ans;
    }
};