class Solution {
public:
    
    bool hasAllCodes(string s, int k) {
        string cur="";
        set<string> st;
        for(int i=0 ; i<s.size() ; i++){
            cur.push_back(s[i]);
            if(i>=k-1){
                st.insert(cur);
                cur.erase(0,1);
            }
        }
        return st.size()==(1<<k);
    }
};