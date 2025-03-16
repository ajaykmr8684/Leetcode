class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int left = 0;
        int right = s1.length() - 1;

        for(int i = 0; i < s2.length(); ++i) {
            string temp = s2.substr(left, s1.length());
            sort(temp.begin(), temp.end());
            string original = s1;
            sort(original.begin(), original.end());

            if(temp == original) {
                return true;
            }

            left++;
        }

        return false;
    }
};