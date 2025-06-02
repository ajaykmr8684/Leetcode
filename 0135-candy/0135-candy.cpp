class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        // Step 1: Initialize left-to-right and right-to-left arrays with 1
        vector<int> L2R(n, 1), R2L(n, 1);

        // Step 2: Left to Right traversal
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                L2R[i] = L2R[i - 1] + 1;
            }
        }

        // Step 3: Right to Left traversal
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                R2L[i] = R2L[i + 1] + 1;
            }
        }

        // Step 4: Calculate the total candies by taking max at each index
        int totalCandies = 0;
        for (int i = 0; i < n; i++) {
            totalCandies += max(L2R[i], R2L[i]);
        }

        return totalCandies;
    }
};