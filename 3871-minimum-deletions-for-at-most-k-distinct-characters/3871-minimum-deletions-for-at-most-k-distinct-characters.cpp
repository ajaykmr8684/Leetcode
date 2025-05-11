class Solution {
public:
    int minDeletion(string s, int k) {
        unordered_map<char,int> mp;
        int distinct=0;

        for(char ch:s){
            if(mp.find(ch)==mp.end()){
                distinct++;
            }
            mp[ch]++;
        }

        priority_queue<int,vector<int>, greater<int>>pq;
        for(pair<int,int> p:mp){
            pq.push(p.second);
        }

        int cnt=0;
        while(!pq.empty() and distinct>k){
            cnt+=pq.top();
            pq.pop();
            distinct--;
        }
        return cnt;
    }
};