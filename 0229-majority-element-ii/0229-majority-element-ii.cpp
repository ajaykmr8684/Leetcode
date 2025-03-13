class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int candidate1 =NULL;
        int count1 = 0;
        int candidate2 = NULL;
        int count2 = 0;

        for(int i = 0; i < nums.size(); ++i) {
            if(candidate1 == nums[i]) {
                count1++;
            }
            else if(candidate2 == nums[i]) {
                count2++;
            }
            else if(count1 == 0) {
                candidate1 = nums[i];
                count1 = 1;
            }
            else if(count2 == 0) {
                candidate2 = nums[i];
                count2 = 1;
            }
            else
            {
                count1--;
                count2--;
            }
        }

        vector<int> result;
        int freq1 = 0;
        int freq2 = 0;

        for(int &num: nums) {
            if(num == candidate1) freq1++;
            else if(num == candidate2) freq2++;
        }

        if(freq1 > floor(nums.size()/3)){
            result.push_back(candidate1);
        }

        if(freq2 > floor(nums.size()/3)) {
            result.push_back(candidate2);
        }

        return result;
    }
};