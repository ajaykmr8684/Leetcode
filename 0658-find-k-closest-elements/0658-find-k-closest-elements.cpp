class Solution {
public:
    typedef pair<int, int> P;
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<P> pq;

        for(int i = 0; i < arr.size(); ++i) {
            pq.push({abs(x- arr[i]), arr[i]});

            if(pq.size() > k) {
                while(pq.size() > k) {
                    pq.pop();
                }
            } 
        }

        vector<int> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();

        }

        sort(begin(ans), end(ans));

        return ans;

    }
};