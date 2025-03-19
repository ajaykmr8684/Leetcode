class MyStack {
public:
    queue<int> q;
    MyStack() {
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        if(q.empty()) return -1;
        int s = q.size();

        for(int i = 1; i < s; ++i) {
            q.push(q.front());
            q.pop();
        }

        int el = q.front();
        q.pop();
        return el;
    }
    
    int top() {
        if(q.empty()) return -1;
        return q.back();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */