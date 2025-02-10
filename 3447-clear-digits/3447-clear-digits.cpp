class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;
        string ans = "";

        for(auto c: s) {
            if(isdigit(c))
            {
                st.pop();
            }
            else st.push(c);
        }

        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};