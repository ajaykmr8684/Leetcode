class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
       
        vector<int> unique;
        unique.push_back(nums[0]);

        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i] != nums[i-1]) {
                unique.push_back(nums[i]);
            }
        }

        //Computing
        int ans = 0;
        for(int i = 1; i < unique.size()-1; ++i) {

            if( unique[i] < unique[i-1] && unique[i] < unique[i+1]){
                ans++;
            }
            else if(unique[i] > unique[i-1] && unique[i] > unique[i+1]) {
                ans++;
            }
        }

        return ans;

    }
};