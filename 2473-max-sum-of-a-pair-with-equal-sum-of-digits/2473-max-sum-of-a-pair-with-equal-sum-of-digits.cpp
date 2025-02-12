class Solution {
public:
    int getSumOfDigits(int n) {
        int temp = n;
        int sum = 0;

        while(temp) {
            int dg = temp%10;
            sum += dg;
            temp /= 10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        int ans = -1;
        unordered_map<int, priority_queue<int>> umap;

        for(auto it: nums)
        {
            umap[getSumOfDigits(it)].push(it);
        }

        for(auto it: umap) {
            if(it.second.size() <=1) continue;
            int top1 = it.second.top();
            it.second.pop();
            int top2 = it.second.top();
            it.second.pop();

            ans = max(ans, top1+top2);
        }

        return ans;
    }

};