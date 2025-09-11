class Solution {
public:
    string sortVowels(string s) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'I', 'E', 'O', 'U'};
        string vow;
        for(auto it: s) {
            if(vowels.find(it) != vowels.end()) {
                vow.push_back(it);
            }
        }

        sort(vow.begin(), vow.end());
        int z = 0;
        for(int i = 0; i < s.length(); i++) {
            if(vowels.find(s[i]) != vowels.end()) {
                s[i] = vow[z];
                z++;
            }
        }

        return s;
    }
};