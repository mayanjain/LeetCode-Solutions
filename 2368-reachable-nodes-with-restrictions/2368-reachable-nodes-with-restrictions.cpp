class Solution {
public:
    int count=0;
    
    void dfs(vector<set<int>>& v,int cur,set<int>& rest){
        if(rest.count(cur))return;
        count++;
        for(auto& i:v[cur]){
            v[i].erase(cur);
            dfs(v,i,rest);
        }
    }
    
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<set<int>> v(n);
        for(auto& i:edges){
            v[i[0]].insert(i[1]);
            v[i[1]].insert(i[0]);
        }
        set<int> rest(restricted.begin(),restricted.end());
        dfs(v,0,rest);
        return count;
    }
};