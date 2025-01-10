class MyQueue {
    stack<int> st1;
    stack<int> st2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        st1.push(x);

    }
    
    int pop() {
        swap(st1, st2);
        while(!st2.empty())
        {
            st1.push(st2.top());
            st2.pop();
        }
        int po = st1.top();
        st1.pop();
        swap(st1, st2);
        while(!st2.empty())
        {
            st1.push(st2.top());
            st2.pop();
        }
        return po;
    }
    
    int peek() {
        while(!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }
        int pe = st2.top();
                while(!st2.empty())
        {
            st1.push(st2.top());
            st2.pop();
        }
        return pe;
    }
    
    bool empty() {
       return st1.empty();
    }
};

