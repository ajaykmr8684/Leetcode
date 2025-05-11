class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        int i = 0;
        
        while(i < n-2) {
            if(arr[i] % 2 == 1) {
                if(arr[i+1] % 2 == 1 && arr[i+2] % 2 == 1) return true;
                else i = i+3;
            }
            i++;
        }

        return false;
    }
};