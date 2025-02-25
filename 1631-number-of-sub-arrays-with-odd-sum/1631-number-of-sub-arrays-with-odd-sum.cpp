class Solution {
public:
    int M = 1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int evenCounts = 1;
        int oddCounts = 0;
        int ans = 0;
        int sum = 0;

        for(int i = 0; i < arr.size(); ++i) {
            sum += arr[i];
            if(sum % 2 == 0){
                ans = (ans + oddCounts) % M;
                evenCounts++;
            } 
            else {
                ans = (ans + evenCounts) % M;
                oddCounts++;
            }

        }

        return ans;
    }
};