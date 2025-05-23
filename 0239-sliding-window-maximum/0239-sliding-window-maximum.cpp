class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        deque<int> dq;
        vector<int> ans;
        for(int i = 0; i < n; ++i) {
            //step 1
            while( !dq.empty() && dq.front() <=i - k) {
                dq.pop_front();
            }

            //step 2
            while(!dq.empty() && nums[i] > nums[dq.back()]) {
                dq.pop_back();
            }

            //step 3
            dq.push_back(i);

            //step 4

            if(i >= k-1) {
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};