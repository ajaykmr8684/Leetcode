class Solution {
public:
    int n;
    int Q;
    bool diffArray(vector<vector<int>> queries, vector<int> &nums, int k) {
        vector<int> diff(nums.size(), 0);

        for(int i = 0; i <=k; ++i) {
            int l = queries[i][0];
            int r = queries[i][1];
            int val = queries[i][2];

            diff[l] += val;
            if(r+1 < n) diff[r+1] -=val;
        }

        //taking cummulative sum
        int cumSum = 0;
        for(int i = 0; i < diff.size(); ++i) {
            cumSum += diff[i];
            diff[i] = cumSum;

            if(nums[i] - diff[i] > 0) return false;
        }

        return true;
    
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        n = nums.size();
        Q = queries.size();

        auto lamba = [](int x) {
            return x == 0;
        };

        if(all_of(begin(nums), end(nums), lamba)) {
            return 0;
        }

        int l = 0;
        int r = Q - 1;
        int k = -1;
        
        while(l <= r) {
            int mid = l + (r - l)/2;

            if(diffArray(queries, nums, mid)) {
                k = mid + 1; //possible ans
                r = mid -1;
            }else l = mid+1;
        }

        return k;
    }
};