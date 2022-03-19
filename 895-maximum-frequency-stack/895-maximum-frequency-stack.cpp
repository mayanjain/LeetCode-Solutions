class FreqStack {
public:
    unordered_map<int,int> count;
    vector<vector<int>> freq;
    int mx=0;
    FreqStack() {
        freq.resize(2*1e4+5);
    }
    
    void push(int val) {
        freq[++count[val]].push_back(val);
        mx=max(count[val],mx);
    }
    
    int pop() {
        auto ans=freq[mx].back();
        freq[mx].pop_back();
        if(freq[mx].size()==0)mx--;
        count[ans]--;
        return ans;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */