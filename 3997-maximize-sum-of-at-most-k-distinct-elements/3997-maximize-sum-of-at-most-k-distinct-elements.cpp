class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
       priority_queue<int, vector<int>, greater<int>> pq;
       vector<int> ans;
       set<int> st(nums.begin(), nums.end());

       for(auto it: st) {
        pq.push(it);
        if(pq.size() > k) {
            pq.pop();
        }
       }

       while(!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
       }

        reverse(ans.begin(), ans.end());
       return ans; 
    }
};