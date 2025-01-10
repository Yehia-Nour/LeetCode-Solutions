class MyStack {
    queue<int> qu1;
    queue<int> qu2;
public:
    MyStack() {
    }
    
    void push(int x) {
        qu2.push(x);
        while (!qu1.empty()) {
            qu2.push(qu1.front());
            qu1.pop();
        }
        swap(qu1, qu2);
    }
    
    int pop() {
        int remove = qu1.front();
        qu1.pop();
        return remove;
    }
    
    int top() {
        return qu1.front();
    }
    
    bool empty() {
        return qu1.empty();
    }
};

