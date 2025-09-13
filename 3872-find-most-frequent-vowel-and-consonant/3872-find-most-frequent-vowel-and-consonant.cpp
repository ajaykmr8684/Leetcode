class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char, int> mp;
        unordered_map<char, int> cons;

        for(int i = 0; i < s.length(); ++i) {
            mp[s[i]]++;
        }

        int maxVowels = 0;
        int maxCons = 0;

        for(auto it: mp) {
            if(it.first == 'a' || it.first  == 'e' || it.first  == 'i' || it.first  == 'o' || it.first  == 'u') {
                maxVowels = max(maxVowels, it.second);
            }
            else maxCons = max(maxCons, it.second);
        }

        return maxVowels + maxCons;
    }
};