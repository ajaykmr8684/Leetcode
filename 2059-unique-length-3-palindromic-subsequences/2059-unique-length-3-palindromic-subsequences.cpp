class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        int result = 0;

        unordered_set<char> letters;
        for(auto it: s) {
            letters.insert(it);
        }

        for(char letter: letters) {
            int left_idx = -1;
            int right_idx = -1;

            for(int i = 0; i < n; ++i)
            {
                if(letter == s[i]) {
                    if(left_idx == -1) left_idx = i;
                    right_idx = i;
                }
            }

            unordered_set<char> uniques;
            for(int i = left_idx + 1; i <= right_idx-1; ++i)
            {
                uniques.insert(s[i]);
            }

            result += uniques.size();
        }

        return result;
    }
};