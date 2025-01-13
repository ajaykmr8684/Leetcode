class Solution {
public:
    int minimumLength(string s) {
        vector<int> count(26, 0);
        int result = 0;

        for(int i = 0; i < s.length(); ++i)
        {
            count[s[i] - 'a']++;
        }

        for(int i = 0; i < 26; ++i)
        {
            if(count[i] == 0) continue;
            if(count[i] % 2 == 0) result +=2;
            else result +=1;
        }

        return result;

    }
};