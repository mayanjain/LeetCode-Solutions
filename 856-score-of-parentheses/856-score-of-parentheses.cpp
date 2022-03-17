class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);
        for(int i=0 ; i<s.size() ; i++){
            if(s[i]=='(')st.push(0);
            else{
                auto top=st.top();
                st.pop();
                auto ls=st.top();
                st.pop();
                st.push(ls+max(2*top,1));
            }
        }
        return st.top();
    }
};