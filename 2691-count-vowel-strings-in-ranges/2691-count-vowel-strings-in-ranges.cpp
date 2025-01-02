class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> ans;
        int n = words.size();
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        vector<int> cSum(n);

        //Cummulative sum of words
        int sum = 0;
        for(int i = 0; i < n; ++i) {
            if(vowels.find(words[i][0]) != vowels.end()  && vowels.find(words[i].back()) != vowels.end()) sum++;
            cSum[i] = sum;
        }

        for(auto row: queries) {
            int start = row[0];
            int end = row[1];

            int result = cSum[end] - ((start > 0) ? cSum[start - 1] : 0);

            ans.push_back(result);
        }

        return ans;
    }
};