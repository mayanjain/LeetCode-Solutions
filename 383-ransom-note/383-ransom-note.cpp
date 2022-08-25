class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        multiset<char> st;
        for(auto& i:ransomNote)st.insert(i);
        for(auto& i:magazine){
            if(st.count(i))st.erase(st.lower_bound(i));
        }
        return st.size()==0;
    }
};