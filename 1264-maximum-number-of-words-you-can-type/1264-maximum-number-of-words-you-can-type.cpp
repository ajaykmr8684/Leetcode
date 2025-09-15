class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) { //"ad"
        unordered_set<char> st;
        int ans = 0;
        bool canType = true;
        for(char it: brokenLetters) {
            st.insert(it); 
        }

            // ['a', 'd'];


            for(int i = 0; i < text.length(); ++i) {
                if(text[i] == ' ') {
                    if(canType) {
                        ans++;
                    }
                    canType = true;
                }
                else if(st.find(text[i]) != st.end()){
                    canType = false;
                }
            }

            if(canType) ans++;
        return ans;

    }
};