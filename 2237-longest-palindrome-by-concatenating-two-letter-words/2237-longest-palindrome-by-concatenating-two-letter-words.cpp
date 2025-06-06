class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;

        int result = 0;

        for(auto word: words) {
            string reversed = word;
            swap(reversed[0], reversed[1]);

            if(mp[reversed] > 0) {
                result +=4;
                mp[reversed]--;
            }
            else mp[word]++;
        }

        // Same

        for(auto it: mp) {
            string word = it.first;
            int count = it.second;

            if(word[0] == word[1] && count > 0) {
                result +=2;
                break;
            }
        }


        return result;
    }
};