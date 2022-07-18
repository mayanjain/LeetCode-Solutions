class Solution {
public:
    bool solve(vector<vector<int>>& v,int cur,unordered_set<int>& st,vector<bool>& done){
        if(done[cur])return true;
        if(st.count(cur))return false;
        st.insert(cur);
        for(auto& i:v[cur]){
            if(!solve(v,i,st,done))return false;
        }
        done[cur]=1;
        return true;
    }
    
    bool canFinish(int total, vector<vector<int>>& req) {
        vector<vector<int>> v(total);
        for(auto& i:req){
            v[i[0]].push_back(i[1]);
        }
        vector<bool> done(total);
        for(int i=0 ; i<total ; i++){
            unordered_set<int> st;
            if(!solve(v,i,st,done))return false;
        }
        return true;
    }
};