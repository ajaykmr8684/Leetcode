class Solution {
public:
    int minimumLength(string s) {
        vector<int> count(26, 0);
        int result = 0;
        int deleted = 0;

        for(int i = 0; i < s.length(); ++i)
        {
            count[s[i] - 'a']++;

            if(count[s[i] - 'a'] == 3)
            {
                count[s[i] - 'a'] -=2;
                deleted += 2;
            } 

        }
        return s.length() - deleted;

    }
};