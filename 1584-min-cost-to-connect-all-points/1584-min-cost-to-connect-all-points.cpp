class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& p) {
        int n=p.size(),cur=0,ans=0;
        vector<bool> seen(n);
        vector<int> dis(n,INT_MAX);
        for(int i=0 ; i<n-1 ; i++){
            int x=p[cur][0],y=p[cur][1];
            seen[cur]=1;
            for(int j=0 ; j<n ; j++){
                if(seen[j])continue;
                dis[j]=min(dis[j],abs(x-p[j][0])+abs(y-p[j][1]));
            }
            cur=min_element(dis.begin(),dis.end())-dis.begin();
            ans+=dis[cur];
            dis[cur]=INT_MAX;
        }
        return ans;
    }
};