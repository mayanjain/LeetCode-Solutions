class Solution {
public:
    vector<long> dp;
    long mod=1e9+7;
    
    long solve(int cur,int n,int delay,int forget){
        if(dp[cur]!=-1)return dp[cur];
        long ans=1;
        if(cur+forget<=n)ans--;
        for(int i=cur+delay ; i<min(cur+forget,n+1) ; i++){
            ans+=solve(i,n,delay,forget);
            ans%=mod;
        }
        return dp[cur]=ans%mod;
    }
    
    int peopleAwareOfSecret(int n, int delay, int forget) {
        dp=vector<long> (n+1,-1);
        return solve(1,n,delay,forget);
    }
};