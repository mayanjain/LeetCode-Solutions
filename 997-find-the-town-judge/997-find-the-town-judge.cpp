class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(trust.size()==0){
            if(n==1)return 1;
            return -1;
        }
        unordered_map<int,int> mp;
        unordered_set<int> st;
        for(auto& i:trust){
            mp[i[1]]++;
            st.insert(i[0]);
        }
        for(auto& i:mp){
            if(i.second==n-1 && !st.count(i.first))return i.first;
        }
        return -1;
    }
};