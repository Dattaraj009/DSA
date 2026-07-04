class MyStack {
public:
    MyStack() {
        
    }
    queue<int> q;
    void push(int x) {
        if(q.empty()){
            q.push(x);
            return;
        }
        q.push(x);
        int n = q.size();
        for(int i=0;i<n-1;i++){
            q.push(q.front());
            q.pop();
        }
        
    }
    
    int pop() {
        int x = q.front();
        q.pop();
        return x;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        if(q.size() > 0) return false;
        return true;
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