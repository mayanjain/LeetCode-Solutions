class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> v(n+1);
        for(auto& i:times){
            v[i[0]].push_back({i[1],i[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});
        vector<int> dist(n+1,1e9);
        dist[k]=dist[0]=0;
        vector<bool> vis(n+1,false);
        while(pq.size()){
            auto [time,cur]=pq.top();
            pq.pop();
            if(vis[cur])continue;
            for(auto& i:v[cur]){
                auto [j,t]=i;
                if(time+t<dist[j]){
                    dist[j]=time+t;
                    pq.push({time+t,j});
                }
            }
            vis[cur]=1;
        }
        auto mx=*max_element(dist.begin(),dist.end());
        if(mx==1e9)return -1;
        return mx;
    }
};