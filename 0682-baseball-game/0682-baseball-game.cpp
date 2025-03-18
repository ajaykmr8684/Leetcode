class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;

        for(auto it: operations) {
            if(it == "C") {
                st.pop();
            }
            else if( it == "D") {
                int prevScore = st.top();
                st.push(prevScore * 2);
            }
            else if( it == "+") {   
                int firstTop = st.top();
                st.pop();
                int secondTop = st.top();
                st.pop();
                int sum = firstTop + secondTop;
                st.push(secondTop);
                st.push(firstTop);
                st.push(sum);
            }
            else {
                st.push(stoi(it));
            }
        }

        int ans = 0;
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }

        return ans;
        
    }
};