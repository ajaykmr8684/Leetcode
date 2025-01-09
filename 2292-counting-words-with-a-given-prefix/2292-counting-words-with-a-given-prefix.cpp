class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;
        int n = words.size();

        for(int i = 0; i < n; ++i)
        {
            if(words[i].substr(0, pref.length()) == pref) ans++;
        }

        return ans;
    }
};