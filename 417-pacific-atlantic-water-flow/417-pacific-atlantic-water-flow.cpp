class Solution {
public:
    vector<vector<int>> dp,ans;
    
    void solve(vector<vector<int>>& h,int i,int j,int dir,int last){
        int n=h.size(),m=h[0].size();
        if(i==n || j==m || i<0 || j<0 || h[i][j]<last || dp[i][j]==dir || dp[i][j]==3)return;
        dp[i][j]+=dir;
        if(dp[i][j]==3)ans.push_back({i,j});
        solve(h,i+1,j,dir,h[i][j]);
        solve(h,i,j+1,dir,h[i][j]);
        solve(h,i-1,j,dir,h[i][j]);
        solve(h,i,j-1,dir,h[i][j]);
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        int n=h.size(),m=h[0].size();
        dp.resize(n,vector<int>(m));
        for(int i=0 ; i<n ; i++){
            solve(h,i,0,1,INT_MIN);
            solve(h,i,m-1,2,INT_MIN);
        }
        for(int j=0 ; j<m ; j++){
            solve(h,0,j,1,INT_MIN);
            solve(h,n-1,j,2,INT_MIN);
        }
        return ans;
    }
};