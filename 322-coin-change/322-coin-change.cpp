class Solution {
public:
    vector<long> dp;
    long solve(vector<int>& coins,int amount){
        if(amount==0)return 0;
        if(dp[amount])return dp[amount];
        long ans=INT_MAX;
        for(int i=0 ; i<coins.size() ; i++){
            if(amount>=coins[i]){
                ans=min(ans,solve(coins,amount-coins[i]));
            }
        }
        return dp[amount]=ans+1;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        dp.resize(amount+1);
        long x=solve(coins,amount);
        return x>=INT_MAX?-1:x;
    }
};