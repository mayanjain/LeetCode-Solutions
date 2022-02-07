class Bitset {
public:
    string s,r;
    int ones=0;
    bool flipped=0;
    
    Bitset(int size) {
        s="";r="";
        for(int i=0 ; i<size ; i++)s+='0',r+='1';
    }
    
    void fix(int idx) {
        ones+=s[idx]==(flipped?'1':'0');
        s[idx]=flipped?'0':'1';
        r[idx]=flipped?'1':'0';
    }
    
    void unfix(int idx) {
        ones-=s[idx]==(flipped?'0':'1');
        s[idx]=flipped?'1':'0';
        r[idx]=flipped?'0':'1';
    }
    
    void flip() {
        flipped=flipped?0:1;
        ones=s.size()-ones;
    }
    
    bool all() {
        return s.size()==ones;
    }
    
    bool one() {
        return ones;
    }
    
    int count() {
        return ones;
    }
    
    string toString() {
        return flipped?r:s;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */