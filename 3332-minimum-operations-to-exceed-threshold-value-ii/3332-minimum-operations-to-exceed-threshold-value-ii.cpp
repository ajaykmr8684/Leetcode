class Solution {
public:
    long long getCalc(int x, int y) {
    return (long long)min(x, y) * 2 + max(x, y);
}
    int minOperations(vector<int>& nums, int k) {
        int ans = 0;
        priority_queue<long long, vector<long long>, greater<long long>> minHeap;

        for(auto it: nums) {
            minHeap.push(it);
        }

        while(true) {
            if(minHeap.size()<=1) break;
            if(minHeap.top() >= k) break;

            int top1 = minHeap.top();
            minHeap.pop();
            int top2 = minHeap.top();
            minHeap.pop();

            long long temp = getCalc(top1, top2);
            minHeap.push(temp);
            ans++;
        }

        return ans;
    }
};