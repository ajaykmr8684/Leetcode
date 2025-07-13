class Solution {
public:
    string reverseStr(string s) {
        int i = 0;
        int j = s.length() - 1;

        while (i <= j) {
            swap(s[i], s[j]);
            i++;
            j--;
        }

        return s;
    }
    string processStr(string s) {
        string result;
        for(int i = 0; i < s.length(); ++i) {
        if(s[i] == '#') {
            result += result;
        }
        else if(s[i] == '*') {
            if(result.length() > 0) result.pop_back();
        }
        else if(s[i] == '%') {
            result = reverseStr(result);
        }
        else {
            result.push_back(s[i]);
        }

    }

        return result;
    }
};