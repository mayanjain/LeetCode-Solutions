class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>> v(n);
        for(auto& i:edges){
            v[i[0]].push_back(i[1]);
            v[i[1]].push_back(i[0]);
        }
        queue<int> q;
        q.push(0);
        set<int> vis,rest;
        for(auto& i:restricted)rest.insert(i);
        vis.insert(0);
        while(q.size()){
            for(int i=q.size() ; i>0 ; i--){
                auto cur=q.front();
                q.pop();
                for(auto& j:v[cur]){
                    if(rest.count(j) || vis.count(j))continue;
                    q.push(j);
                    vis.insert(j);
                }
            }
        }
        return vis.size();
    }
};