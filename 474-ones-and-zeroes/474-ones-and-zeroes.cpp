class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len=strs.size();
        int dp[len+1][m+1][n+1];
        memset(dp,0,sizeof dp);
        for(int i=1 ; i<=len ; i++){
            int zero=count(strs[i-1].begin(),strs[i-1].end(),'0');
            int one=strs[i-1].size()-zero;
            for(int j=0 ; j<=m ; j++){
                for(int k=0 ; k<=n ; k++){
                    dp[i][j][k]=dp[i-1][j][k];
                    if(zero<=j && one<=k){
                        dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-zero][k-one]+1);
                    }
                }
            }
        }
        return dp[len][m][n];
    }
};