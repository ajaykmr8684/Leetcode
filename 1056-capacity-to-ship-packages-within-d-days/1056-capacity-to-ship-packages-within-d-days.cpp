class Solution {
public:
    int canShip(vector<int> & w, int mid, int days) {
        int actualDays = 1;
        int sum = 0;
         for(auto &it: w) {
            if(it + sum > mid) {
                actualDays++;
                sum = it;
            }
            else {
                sum += it;
            }
         }

         return actualDays <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end());
        int r = accumulate(weights.begin(), weights.end(), 0);

        while(l <= r) {
            int mid = l + (r - l) / 2;

            if(canShip(weights, mid, days)) {
                r = mid - 1;
            }
            else l = mid + 1;
        }

        return l;
    }
};