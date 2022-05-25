class Solution {
public:
    int ans=-1;
    
    void solve(vector<vector<int>>& board,vector<pair<int,int>>& pos,int cur,int steps,vector<int>& dp){
        int n=board.size();
        if(cur>n*n)return;
        if(dp[cur]<=steps)return;
        dp[cur]=steps;
        if(cur==n*n){
            if(ans==-1)ans=steps;
            ans=min(ans,steps);
            return;
        }
        for(int i=1 ; i<=6 ; i++){
            if(cur+i>n*n)return;
            int x=pos[cur+i].first,y=pos[cur+i].second;
            if(board[x][y]!=-1){
                solve(board,pos,board[x][y],steps+1,dp);
            }
            else solve(board,pos,cur+i,steps+1,dp);
        }
    }
    
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size(),cur=1;
        vector<int> dp(n*n+1,INT_MAX);
        vector<pair<int,int>> pos(n*n+1);
        for(int i=n-1 ; i>=0 ; i--){
            if((n-i)%2){
                for(int j=0 ; j<n ; j++){
                    pos[cur++]={i,j};
                }
            }
            else{
                for(int j=n-1 ; j>=0 ; j--){
                    pos[cur++]={i,j};
                }
            }
        }
        solve(board,pos,1,0,dp);
        return ans;
    }
};