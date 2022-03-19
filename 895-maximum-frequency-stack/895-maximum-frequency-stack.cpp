class FreqStack {
public:
    unordered_map<int,int> count;
    map<int,vector<int>> freq;
    int mx=0;
    FreqStack() {
        
    }
    
    void push(int val) {
        freq[++count[val]].push_back(val);
        mx=max(count[val],mx);
    }
    
    int pop() {
        auto ans=freq[mx].back();
        freq[mx].pop_back();
        count[ans]--;
        if(!freq[mx].size())freq.erase(mx),mx--;
        return ans;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */