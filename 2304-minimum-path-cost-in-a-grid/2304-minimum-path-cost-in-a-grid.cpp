class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& cost) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,INT_MAX));
        dp[0]=grid[0];
        int ans=INT_MAX;
        for(int i=1 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                for(int k=0 ; k<n ; k++){
                    dp[i][k]=min(dp[i][k],dp[i-1][j]+cost[grid[i-1][j]][k]+grid[i][k]);
                }
            }
        }
        for(int i=0 ; i<n ; i++){
            ans=min(ans,dp[m-1][i]);
        }
        return ans;
    }
};