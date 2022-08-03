class MyQueue {
public:
    stack<int> st;
    stack<int> auxst;
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!st.empty())
        {
            int a = st.top();
            auxst.push(a);
            st.pop();
        }
        st.push(x);
        while(!auxst.empty())
        {
            int b = auxst.top();
            st.push(b);
            auxst.pop();
        }
    }
    
    int pop() {
        int c = st.top();
        st.pop();
        return c;
    }
    
    int peek() {
        int d = st.top();
        return d;
    }
    
    bool empty() {
        return st.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */