class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n=seats.size();
        vector<int> dis(n,1e5);
        if(seats[0]==1)dis[0]=0;
        for(int i=1 ; i<n ; i++){
            if(!seats[i])dis[i]=dis[i-1]+1;
            else dis[i]=0;
        }
        if(seats[n-1]==1)dis[n-1]=0;
        int ans=dis[n-1];
        for(int i=n-2 ; i>=0 ; i--){
            if(!seats[i])dis[i]=min(dis[i+1]+1,dis[i]);
            else dis[i]=0;
            ans=max(ans,dis[i]);
        }
        return ans;
    }
};