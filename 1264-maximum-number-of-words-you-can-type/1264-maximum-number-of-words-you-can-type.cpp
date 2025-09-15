class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> st;
        for(auto it: brokenLetters) st.insert(it);
        int ans = 0;
        bool canType = true;

        for(int i = 0; i < text.length(); ++i) {
            if(text[i] == ' ') {
                if(canType) {
                    ans++;
                }
                canType = true;
            }
            else if(st.find(text[i]) != st.end()) {
                canType = false;
            }
        }

        if(canType) ans++;

        return ans;
    }
};