class Solution {
public:
    // int solve(string& word1,string& word2,int x,int y,vector<vector<int>>& dp){
    //     int sz1=word1.size(),sz2=word2.size();
    //     if(y==sz2)return sz1-x;
    //     if(x==sz1)return sz2-y;
    //     if(word1[x]==word2[y])return solve(word1,word2,x+1,y+1,dp);
    //     if(dp[x][y])return dp[x][y];
    //     return dp[x][y]=min({solve(word1,word2,x+1,y,dp),solve(word1,word2,x+1,y+1,dp),solve(word1,word2,x,y+1,dp)})+1;
    // }
    
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1,vector<int>(word2.size()+1));
        for(int i=0 ; i<=word2.size() ; i++){
            dp[0][i]=i;
        }
        for(int i=0 ; i<=word1.size() ; i++){
            dp[i][0]=i;
        }
        for(int i=1 ; i<=word1.size() ; i++){
            for(int j=1 ; j<=word2.size() ; j++){
                if(word1[i-1]==word2[j-1])dp[i][j]=dp[i-1][j-1];
                else{
                    dp[i][j]=min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]})+1;
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
};