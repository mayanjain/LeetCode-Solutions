class MyStack {
public:
    queue<int> q;
    
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        queue<int> f;
        while(q.size()>1){
            f.push(q.front());
            q.pop();
        }
        int ans=q.front();
        q.pop();
        swap(q,f);
        return ans;
    }
    
    int top() {
        queue<int> f;
        while(q.size()>1){
            f.push(q.front());
            q.pop();
        }
        int ans=q.front();
        f.push(ans);
        swap(q,f);
        return ans;
    }
    
    bool empty() {
        return q.size()==0;
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