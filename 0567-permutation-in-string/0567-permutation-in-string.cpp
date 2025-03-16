class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int i = 0, j = 0;

        vector<int> s1Freq(26, 0);
        vector<int> s2Freq(26, 0);

        for(int k = 0; k < s1.length(); ++k) s1Freq[s1[k] - 'a']++;

        while(j < s2.length()) {
            if(j -i + 1 > s1.length()) {
                s2Freq[s2[i] - 'a']--;
                i++;
            }

            s2Freq[s2[j] - 'a']++;

            if(s1Freq == s2Freq) return true;
            j++;

        }

        return false;
    }
};