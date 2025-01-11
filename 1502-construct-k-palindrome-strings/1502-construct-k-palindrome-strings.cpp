class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.length();

        if(n < k) return false;
        if(n == k) return true;

        vector<int> freq(26, 0);
        for(auto ch: s)
        {
            freq[ch - 'a']++;
        }

        int oddCount = 0;

        for(int i = 0; i < 26; ++i)
        {
            if(freq[i] % 2 != 0) oddCount++;
        }

        return oddCount <= k;
    }
};