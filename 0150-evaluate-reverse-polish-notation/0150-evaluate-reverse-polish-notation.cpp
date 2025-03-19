class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(auto val: tokens)
        {
            if(val == "*")
            {
                int temp1 = st.top();
                st.pop();
                int temp2 = st.top();
                st.pop();
                st.push(temp1 * temp2);
            }
            else if(val == "/")
            {
                int temp1 = st.top();
                st.pop();
                int temp2 = st.top();
                st.pop();

                st.push(temp2 / temp1);
                
            }
            else if(val == "-")
            {
                int temp1 = st.top();
                st.pop();
                int temp2 = st.top();
                st.pop();

                st.push(temp2 - temp1);
            }
            else if(val == "+")
            {
                int temp1 = st.top();
                st.pop();
                int temp2 = st.top();
                st.pop();
                st.push(temp1 + temp2);
            }
            else
            {
                st.push(stoi(val));
            }
        }

        return st.top();
    }
};