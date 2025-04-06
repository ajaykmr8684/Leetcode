class Solution {
public:
    void reverse(string &s, int start, int end) {
        int i = start;
        int j = end;

        while(i < j) {
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
        } 
    }
    string reverseWords(string s) {
        int start = 0;
        for(int i = 0; i < s.length(); ++i) {
            if(s[i] == ' ') {
                reverse(s, start, i - 1);
                start = i+1;
            }
            else if(i == s.length() - 1) {
                reverse(s, start, i);
            }
        }

        return s;
    }
};