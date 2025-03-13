class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        if(n == 1) return true;



        int i = 0, j = n - 1;

        while(i < j) {
            if(!isalnum(s[i]) || s[i] == ' '){
                i++;
                continue;
            }
            if(!isalnum(s[j]) || s[j] == ' ') {
                j--;
                continue;
            } 

            if(tolower(s[i]) != tolower(s[j])) {
                cout << s[i] << i << " " << s[j] << j;
                return false;
            }
            i++;
            j--;
        }

        return true;
    }
};