class MyQueue {
public:
    stack<int> st1, st2;

    MyQueue() {}

    void push(int x) { st1.push(x); }

    int pop() {
        if (st2.size()) {
            int t = st2.top();
            st2.pop();
            return t;
        }
        while (st1.size()) {
            st2.push(st1.top());
            st1.pop();
        }
        int t = st2.top();
        st2.pop();
        return t;
    }

    int peek() {
         if (st2.size()) {
            int t = st2.top();
           
            return t;
        }
        while (st1.size()) {
            st2.push(st1.top());
            st1.pop();
        }
        int t = st2.top();
        return t;
    }

    bool empty() { return !(st1.size() || st2.size()); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */