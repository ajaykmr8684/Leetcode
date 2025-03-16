class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        vector<int> freq(26, 0);
        int i =0;
        int maxFreq = 0;
        int maxWindow = 0;

        for(int j = 0; j < n; ++j) {
            freq[s[j] - 'A']++;

            maxFreq = max(maxFreq, freq[s[j] - 'A']);

            int windowLen = j - i + 1;

            if(windowLen - maxFreq > k) {
                freq[s[i] - 'A']--;
                i++;
            }

            windowLen = j - i + 1;

            maxWindow = max(maxWindow, windowLen);
        }

        return maxWindow;
    }
};