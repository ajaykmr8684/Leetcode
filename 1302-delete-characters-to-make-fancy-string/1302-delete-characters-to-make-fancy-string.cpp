class Solution {
public:
    string makeFancyString(string s) {
        string ans;

        for(int i = 0; i < s.length(); ++i) {
            if(i > 1) {
                if(s[i-1] == s[i] && s[i] == s[i-2]) {
                    continue;
                }
            }
            ans.push_back(s[i]);
        }

        return ans;
    }
};