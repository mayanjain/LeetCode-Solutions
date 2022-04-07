class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        multiset<int,greater<int>> st;
        for(auto& i:stones)st.insert(i);
        while(st.size()>1){
            auto it=st.begin();
            auto it2=it++;
            st.insert(*it2-*it);
            st.erase(it);
            st.erase(it2);
        }
        return *st.begin();
    }
};