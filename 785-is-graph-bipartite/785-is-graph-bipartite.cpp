class Solution {
public:
    
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> col(graph.size());
        for(int i=0 ; i<graph.size() ; i++){
            if(col[i])continue;
            queue<int> q;
            q.push(i);
            col[i]=1;
            while(q.size()){
                for(int i=q.size() ; i>0 ; i--){
                    auto cur=q.front();
                    q.pop();
                    for(auto& v:graph[cur]){
                        if(col[v]==col[cur])return false;
                        if(col[v])continue;
                        col[v]=col[cur]==1?2:1;
                        q.push(v);
                    }
                }
            }
        }
        return true;
    }
};