class Solution {
public:
    bool isPalindrome(string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }

    void backtrack(string& s, int idx, vector<string>& curr,
                   vector<vector<string>>& res) {
        // base case if idx is at end then add it in res as we are already
        // checked for the palindrome
        int n = s.length();
        if (idx == n) {
            res.push_back(curr);
            return;
        }
        // now we have to traverse through the string and take the char from idx
        for (int i = idx; i < n; i++) {
            if (isPalindrome(s, idx, i)) {
                // push starting from idx and of i-idx+1 len
                // add
                curr.push_back(s.substr(idx, i - idx + 1));
                // explore
                backtrack(s, i + 1, curr, res);
                // pop or backtrack
                curr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> curr;
        backtrack(s, 0, curr, res);
        return res;
    }
};