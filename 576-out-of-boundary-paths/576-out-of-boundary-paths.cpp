class Solution {
public:
    int mod=1e9+7;
    int dp[51][51][51];
    
    long paths(int move,int row,int col,int m,int n){
        if(row<0 || row>=m || col<0 || col>=n)return 1;
        if(!move)return 0;
        if(dp[move][row][col]!=-1){
            return dp[move][row][col];
        }
        move-=1;
        long ans=paths(move,row+1,col,m,n);
        ans+=paths(move,row,col+1,m,n);
        ans+=paths(move,row-1,col,m,n);
        ans+=paths(move,row,col-1,m,n);
        return dp[move+1][row][col]=ans%mod;
    }
    
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp,-1,sizeof dp);
        return paths(maxMove,startRow,startColumn,m,n);
    }
};