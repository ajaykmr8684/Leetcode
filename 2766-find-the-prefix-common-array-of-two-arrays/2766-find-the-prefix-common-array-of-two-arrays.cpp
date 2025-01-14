class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> result;
        unordered_map<int, int> freq;
        int count = 0;

        for(int i = 0; i < A.size(); ++i)
        {
            freq[A[i]]++;
            

            if(freq[A[i]] == 2) count++;
            freq[B[i]]++;
            if(freq[B[i]] == 2) count++;
            result.push_back(count);
        }
        return result;
    }
};