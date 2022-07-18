class Solution {
public:
    bool canFinish(int total, vector<vector<int>>& req) {
        vector<vector<int>> v(total);
        vector<int> degree(total),done(total);
        for(auto& i:req){
            v[i[1]].push_back(i[0]);
            degree[i[0]]++;
        }
        queue<int> q;
        for(int i=0 ; i<total ; i++){
            if(!degree[i]){
                q.push(i);
                done[i]=1;
            }
        }
        while(q.size()){
            for(int i=q.size() ; i>0 ; i--){
                auto cur=q.front();
                q.pop();
                for(auto& i:v[cur]){
                    if(--degree[i]==0){
                        q.push(i);
                        done[i]++;
                    }
                }
            }
        }
        for(auto& i:done){
            if(!i)return false;
        }
        return true;
    }
};