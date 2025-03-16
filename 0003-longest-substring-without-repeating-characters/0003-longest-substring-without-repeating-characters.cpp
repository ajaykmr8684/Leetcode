class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;

        int i = 0;
        int j = i;
        int maxAns = 0;
        while(j < s.length()) {
            if(st.find(s[j]) != st.end()) {
                while(st.find(s[j]) != st.end()) {
                    st.erase(s[i]);
                    i++;
                }
            }

            int len = j - i + 1;
            st.insert(s[j]);
            maxAns = max(maxAns, len);
            j++;
        }

        return maxAns;
    }
};