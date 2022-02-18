class Solution {
public:
    
    string removeKdigits(string s,int k) {
        stack<char> st;
        for(auto& c:s){
            while(st.size() && st.top()>c && k){
                k--;
                st.pop();
            }
            if(st.size()==0 && c=='0')continue;
            st.push(c);
        }
        string cur="";
        while(st.size()){
            cur+=st.top();
            st.pop();
        }
        reverse(cur.begin(),cur.end());
        while(cur.size() && k){
            k--;
            cur.pop_back();
        }
        if(cur.size()==0)cur='0';
        return cur;
    }   
};