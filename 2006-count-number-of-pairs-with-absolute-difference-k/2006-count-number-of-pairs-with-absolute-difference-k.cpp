class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        
        int ans = 0;
        
        /* Keeps the frequency of each elements */
        vector<int> arr(201, 0);
        
        for(auto it: nums){
            
            if(it - k >=0) ans += arr[it - k];
            ans += arr[it + k];
            
            arr[it]++;   
            
        }
        return ans;   
        
    }
};