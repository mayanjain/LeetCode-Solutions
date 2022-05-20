class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> dp(n+1,vector<int>(m+1));
        dp[0][1]=1;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(!grid[i][j]){
                    dp[i+1][j+1]=dp[i][j+1]+dp[i+1][j];
                }
                // cout<<dp[i+1][j+1]<<" ";
            }
        // cout<<'\n';
        }
        return dp[n][m];
    }
};