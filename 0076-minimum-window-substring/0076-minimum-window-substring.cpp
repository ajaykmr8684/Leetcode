class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        if(t.length() > n) return "";

        unordered_map<char, int> mp;

        for(char &ch: t) mp[ch]++;

        int requiredCount = t.length();
        int minWindowSize = INT_MAX;
        int start_i = 0;

        int i = 0, j = 0;

        while(j < n) {
            if(mp[s[j]] > 0) {
                requiredCount--;
            }
            mp[s[j]]--;

            while(requiredCount == 0) {
                //just shrink until requiredCount becomes greater than 0 because we can't take out required character from our window.
                int currWindowSize = j - i + 1;

                if(minWindowSize > currWindowSize) {
                    minWindowSize = currWindowSize;
                    start_i = i;
                }

                mp[s[i]]++;
                if(mp[s[i]] > 0) {
                    requiredCount++;
                }
                i++;
            }
            j++;
        }
        cout << minWindowSize;
        return minWindowSize == INT_MAX ? "" : s.substr(start_i, minWindowSize);
    }
};