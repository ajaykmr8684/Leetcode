class Solution {
public:
    int mySqrt(int x) {
        int n = 1;

        int l = 1;
        int r = x/2;
        int ans = x;

        while(l <= r) {
            int mid = l + ( r - l) / 2;

            if(mid == x/mid){
                ans = mid;
                break;
            } 
            else if(mid < x/mid){
                ans = mid;
                l = mid + 1;
            } 
            else r = mid - 1;
        }

        return ans;
    }
};