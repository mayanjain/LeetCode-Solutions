class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st,dt;
        for(auto& i:s){
            if(i=='#'){if(st.size())st.pop();}
            else st.push(i);
        }
        for(auto& i:t){
            if(i=='#'){if(dt.size())dt.pop();}
            else dt.push(i);
        }
        return st==dt;
    }
};