class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        set<pair<int,int>> st;
        for(int i=0 ; i<mat.size() ; i++){
            int ones=0;
            for(auto& j:mat[i])if(j)ones++;
            st.insert({ones,i});
            if(st.size()>k)st.erase(--st.end());
        }
        vector<int> v;
        for(auto& i:st)v.push_back(i.second);
        return v;
    }
};