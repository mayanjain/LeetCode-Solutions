class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<int> dp(m);
        dp[0]=1;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(grid[i][j]){
                    dp[j]=0;
                }
                else if(j)dp[j]+=dp[j-1];
            }
        }
        return dp[m-1];
    }
};