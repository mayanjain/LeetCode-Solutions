class Solution {
public:
    char repeatedCharacter(string s) {
        set<char> st;
        for(auto& i:s){
            if(st.count(i))return i;
            st.insert(i);
        }
        return ' '; 
    }
};