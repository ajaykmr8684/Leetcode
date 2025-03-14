class Solution {
public:
    bool canDis(vector<int> & candies, int mid, long long k) {
        for(int i = 0; i < candies.size(); ++i) {
            k -= candies[i]/mid;

            if(k <=0) return true;
        }

        return k <=0;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
        int maxC = 0;
        long long totalCandies = 0;
        for(int i = 0; i < n; ++i) {
            totalCandies += candies[i];
            maxC = max(maxC, candies[i]);
        }

        if(totalCandies < k) return 0;

        int l = 1;
        int r = maxC;
        long long result = 0;
        while(l <= r) {
            int mid = l + (r-l)/2;

            if(canDis(candies, mid, k)) {
                result = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }

        return result;
    }
};