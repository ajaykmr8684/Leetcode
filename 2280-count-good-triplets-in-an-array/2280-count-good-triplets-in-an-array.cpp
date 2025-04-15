class FenwickTree {
    vector<int> bit;
    int n;
public:
    FenwickTree(int size) {
        n = size;
        bit.assign(n + 1, 0);
    }

    void update(int idx, int delta) {
        idx++;  // Fenwick Tree is 1-based
        while (idx <= n) {
            bit[idx] += delta;
            idx += idx & -idx;
        }
    }

    int query(int idx) {
        idx++;  // 1-based
        int sum = 0;
        while (idx > 0) {
            sum += bit[idx];
            idx -= idx & -idx;
        }
        return sum;
    }
};

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        
        // Map value -> index in nums2
        vector<int> posInNums2(n);
        for (int i = 0; i < n; ++i) {
            posInNums2[nums2[i]] = i;
        }

        // Convert nums1 to their positions in nums2
        vector<int> mapped(n);
        for (int i = 0; i < n; ++i) {
            mapped[i] = posInNums2[nums1[i]];
        }

        // left[i] = count of numbers less than mapped[i] to the left of i
        vector<int> left(n), right(n);
        FenwickTree bit(n);
        for (int i = 0; i < n; ++i) {
            left[i] = bit.query(mapped[i] - 1);
            bit.update(mapped[i], 1);
        }

        // Reset Fenwick Tree for right side
        bit = FenwickTree(n);
        for (int i = n - 1; i >= 0; --i) {
            right[i] = bit.query(n - 1) - bit.query(mapped[i]);
            bit.update(mapped[i], 1);
        }

        // Count total good triplets
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += 1LL * left[i] * right[i];
        }

        return ans;
    }
};