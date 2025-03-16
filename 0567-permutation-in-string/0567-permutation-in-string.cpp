class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        string original = s1;
        sort(original.begin(), original.end());
        for(int i = 0; i < s2.length(); ++i) {
            string temp = s2.substr(i, s1.length());
            sort(temp.begin(), temp.end());
            if(temp == original) {
                return true;
            }
        }

        return false;
    }
};