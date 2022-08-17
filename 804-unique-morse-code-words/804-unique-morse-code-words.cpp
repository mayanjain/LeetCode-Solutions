class Solution {
public:
    vector<string> morse{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> st;
        for(auto& s:words){
            string cur="";
            for(auto& i:s){
                cur+=morse[i-'a'];
            }
            st.insert(cur);
        }
        return st.size();
    }
};