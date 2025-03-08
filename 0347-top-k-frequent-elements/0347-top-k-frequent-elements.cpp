class Solution {
public:
    typedef pair<int, int> P;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> mp;
        for(auto it: nums) mp[it]++;

        priority_queue<P, vector<P>, greater<P>> pq;

        for(auto it: mp) {
            pq.push({it.second, it.first});
            if(pq.size() > k) {
                while(pq.size() > k) pq.pop();
            } 
        }

        while(!pq.empty()) {
            int val = pq.top().second;
            ans.push_back(val);
            pq.pop();
        }
        
        return ans;
    }
};