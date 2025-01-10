class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> result;

        vector<int>  freq2(26);

        for(auto word:words2)
        {
            int arr[26] = {0};

            for(auto ch: word)
            {
                arr[ch - 'a']++;
                freq2[ch-'a'] = max(freq2[ch-'a'], arr[ch- 'a']);
            }
        }

        for(string word: words1)
        {
            int arr[26] = {0};
            for(auto ch: word)
            {
                arr[ch - 'a']++;
            }

            bool isSubset = true;
            for(int i = 0; i < 26; ++i)
            {
                if(arr[i] < freq2[i]) isSubset = false;
            }

            if(isSubset) result.push_back(word);

        }

        return result;

    }
};