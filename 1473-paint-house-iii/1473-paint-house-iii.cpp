class Solution {
public:
    int dp[101][101][21]={};
    
    int solve(vector<int>& houses,vector<vector<int>>& cost,int m,int n,int i,int last,int target){
        if(target<0)return -1;
        if(i==m){
            // cout<<target<<" ";
            if(target)return -1;
            return 0;
        }
        if(houses[i])return solve(houses,cost,m,n,i+1,houses[i],target-(!i || last!=houses[i]));
        if(dp[i][target][last])return dp[i][target][last];
        int ans=INT_MAX;
        for(int j=1 ; j<=n ; j++){
            houses[i]=j;
            int cur=solve(houses,cost,m,n,i+1,j,target-(last!=j));
            if(cur!=-1){
                ans=min(ans,cur+cost[i][j-1]);
            }
            houses[i]=0;
        }
        return dp[i][target][last]=ans==INT_MAX?-1:ans;
    }
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        return solve(houses,cost,m,n,0,0,target);
    }
};