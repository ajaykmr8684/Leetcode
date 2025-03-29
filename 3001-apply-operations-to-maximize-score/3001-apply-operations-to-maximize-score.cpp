const int MOD = 1e9 + 7;

class Solution {
public:
    vector<int> primeScore;
    
    // Function to compute prime scores for numbers up to maxVal
    void computePrimeScores(int maxVal) {
        primeScore.assign(maxVal + 1, 0);
        for (int i = 2; i <= maxVal; i++) {
            if (primeScore[i] == 0) { // Prime number
                for (int j = i; j <= maxVal; j += i) {
                    primeScore[j]++;
                }
            }
        }
    }
    
    long long modExp(long long base, long long exp, long long mod) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) { // If exponent is odd
                result = (result * base) % mod;
            }
            base = (base * base) % mod; // Square the base
            exp /= 2;
        }
        return result;
    }
    
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        int maxNum = *max_element(nums.begin(), nums.end());
        computePrimeScores(maxNum);
        
        vector<int> left(n, -1), right(n, n);
        stack<int> st;
        
        // Compute left boundary
        for (int i = 0; i < n; i++) {
            while (!st.empty() && primeScore[nums[st.top()]] < primeScore[nums[i]]) {
                st.pop();
            }
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        
        while (!st.empty()) st.pop();
        
        // Compute right boundary
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && primeScore[nums[st.top()]] <= primeScore[nums[i]]) {
                st.pop();
            }
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < n; i++) {
            pq.emplace(nums[i], i);
        }
        
        long long res = 1;
        while (k > 0 && !pq.empty()) {
            auto [num, index] = pq.top(); pq.pop();
            int score = (num <= maxNum) ? primeScore[num] : 0;
            long long leftCnt = index - (left[index] == -1 ? -1 : left[index]);
            long long rightCnt = (right[index] == n ? n : right[index]) - index;
            long long operations = min(leftCnt * rightCnt, (long long)k);
            if (operations > 0) {
                res = (res * modExp(num, operations, MOD)) % MOD;
            }
            k -= operations;
        }
        
        return res;
    }
};