class Solution {
public:
    bool dfs(int cur,int col,vector<int>& v,vector<vector<int>>& graph){
        v[cur]=col;
        for(auto& i:graph[cur]){
            if(v[i]==-1){
                if(!dfs(i,col^1,v,graph))return false;
            }
            else if(v[i]==col)return false;
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> v(graph.size()+1,-1);
        for(int i=0 ; i<graph.size() ; i++){
            if(v[i]==-1 && !dfs(i,1,v,graph))return false;
        }
        return true;
    }
};