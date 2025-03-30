class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();

        vector<int> lastOc(26, 0);
        vector<int> result;

        for(int i = 0; i < n; ++i) {
            lastOc[s[i] - 'a'] = i;
        }

        int i = 0;
        int start = 0;
        int end = 0;

        while(i < n) {
            end = max(end, lastOc[s[i] - 'a']);
            if(end == i) {
                result.push_back(end - start + 1);
                start = end + 1;
            }

            i++;
        }

        return result;
    }
};