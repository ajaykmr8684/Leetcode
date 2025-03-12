class Solution {
public:
    int maximumCount(vector<int>& nums) {
        //Just fine the first positive number excluding 0.
        int n = nums.size();

        int low = 0;
        int high = n - 1;
        int positiveIndex = -1;
        int lastNegativeIndex = -1;

        while(low <= high) {
            int mid = low + (high - low)/2;

            if(nums[mid] > 0) positiveIndex = mid;

            if(nums[mid] <= 0) low = mid + 1;
            else high = mid - 1; 
        }

        low = 0;
        high = n - 1;
        while(low <= high) {
            int mid = low + (high - low)/2;

            if(nums[mid] < 0) lastNegativeIndex = mid;

            if(nums[mid] >= 0) high = mid - 1;
            else low = mid + 1; 
        }

        cout << lastNegativeIndex << " " << positiveIndex;
        if(lastNegativeIndex == -1 && positiveIndex == -1) return 0;

        int noOfpositives =  positiveIndex == -1 ? positiveIndex : n - positiveIndex;

        return max(lastNegativeIndex+1, noOfpositives);

    }
};