class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto& i:s){
            if(i=='(')st.push(')');
            else if(i=='{')st.push('}');
            else if(i=='[')st.push(']');
            else{
                if(!st.size())return false;
                if(st.top()!=i)return false;
                st.pop();
            }
        }
        return st.size()==0;
    }
};