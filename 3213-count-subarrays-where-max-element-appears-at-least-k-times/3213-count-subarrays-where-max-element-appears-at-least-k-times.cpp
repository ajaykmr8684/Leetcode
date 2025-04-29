class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());
        int freq = 0;
        long long result = 0;
        

        int i = 0, j = 0;

        while(j < n) {
            
            if(nums[j] == maxi) {
                freq++;
            }

            while(freq >= k) {
                result += n - j;
                if(nums[i] == maxi) {
                    freq--;
                }
                i++;
            }

            j++;
        }

        return result;
    }
};