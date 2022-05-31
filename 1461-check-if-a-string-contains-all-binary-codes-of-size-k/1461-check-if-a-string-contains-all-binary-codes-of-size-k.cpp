class Solution {
public:
    
    bool hasAllCodes(string s, int k) {
        unordered_set<string> st;
        string cur;
        for(int i=0 ; i+k<=s.size() ; i++){
            cur=s.substr(i,k);
            st.insert(cur);
        }
        return st.size()==(1<<k);
    }
};