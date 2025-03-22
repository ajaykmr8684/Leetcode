class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        stack<int> nums;
        bool isDigit = false;
        for (int i = 0; i < (int) s.size(); i++) {
            char c = s[i];
            if (c == ']') {
                isDigit = false;
                vector<char> temp;
                while (st.top() != '[') {
                    temp.push_back(st.top());
                    st.pop();
                }
                st.pop();
                int num = nums.top();
                nums.pop();
                while (num > 0) {
                    for (int t = temp.size() - 1; t >= 0; t--) {
                        st.push(temp[t]);
                    }
                    num--;
                }
            } else if ('0' <= c && c <= '9') {
                int k = c - '0';
                if (isDigit) {
                    k += nums.top()*10;
                    nums.pop();
                    nums.push(k);
                } else {
                    nums.push(k);
                }
                isDigit = true;
            } else {
                isDigit = false;
                st.push(c);
            }
        }
        string result = "";
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};