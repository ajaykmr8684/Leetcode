class StockSpanner {
public:
    stack<pair<int , int>> st;
    int idx = 1;
    int maxi = INT_MIN;
    StockSpanner() {
        // do nothing, fuck you!
    }
    
    int next(int price) {
        int count = 1;
        while(!st.empty() && price >= st.top().first) {
            count += st.top().second;
            st.pop();
        }
        st.push({price, count});
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */