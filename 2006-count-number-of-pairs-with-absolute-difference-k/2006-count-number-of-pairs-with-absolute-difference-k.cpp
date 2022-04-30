class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        
        int ans = 0;
        
        /* Keeps the frequency of each elements */
        unordered_map<int, int> umap;
        
        /* Calculating frequency */
        for(auto it: nums){
            umap[it]++;
        }
        
        /* Using the property of Absolute/Modulus of |a-b| which signifies that
           if a >= b then a-b and if a <b then b - a */
        
        for(auto it: nums){
            
            /* Decreasing the count of current elements as it's being consumed */
            umap[it]--;
            
            
            
            ans = ans + umap[it - k];
            ans = ans + umap[it + k];
            
            
        }
        return ans;   
        
    }
};