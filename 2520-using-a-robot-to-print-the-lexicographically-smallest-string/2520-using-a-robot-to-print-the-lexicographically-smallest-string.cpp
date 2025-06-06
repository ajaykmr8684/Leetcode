class Solution {
public:
    string robotWithString(string s) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        stack<char> st;
        string result = "";
        int minChar = 0;

        for (char c : s) {
            st.push(c);
            freq[c - 'a']--;

            // Update minChar to the current smallest remaining character
            while (minChar < 26 && freq[minChar] == 0) {
                minChar++;
            }

            while (!st.empty() && st.top() <= ('a' + minChar)) {
                result += st.top();
                st.pop();
            }
        }

        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        return result;
    }
};
