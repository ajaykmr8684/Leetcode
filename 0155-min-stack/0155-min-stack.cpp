class MinStack {

    stack<long long> st;
    long long mini;
    
public:
    MinStack() {
        while(!st.empty()) st.pop();
        mini = INT_MAX;
    }
    
    void push(int val) {
        long long temp = val;

        if(st.empty())
        {
            mini = temp;
            st.push(temp);
        }
        else
        {
            if(temp < mini)
            {
                st.push(2 * temp * 1LL - mini);
                mini = temp;
            }
            else
            {
                st.push(temp);
            }
        }

    }
    
    void pop() {
        if (st.empty()) return;
        if(st.top() < mini)
        {
            mini = 2 * mini - st.top();
        }
        st.pop();
    }
    
    int top() {
        if(st.top() > mini)
        {
            return st.top();
        }
        return mini;
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */