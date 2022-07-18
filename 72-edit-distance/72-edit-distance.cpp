class Solution {
public:
    int solve(string& word1,string& word2,int x,int y,vector<vector<int>>& dp){
        int sz1=word1.size(),sz2=word2.size();
        if(y==sz2)return sz1-x;
        if(x==sz1)return sz2-y;
        if(word1[x]==word2[y])return solve(word1,word2,x+1,y+1,dp);
        if(dp[x][y])return dp[x][y];
        return dp[x][y]=min({solve(word1,word2,x+1,y,dp),solve(word1,word2,x+1,y+1,dp),solve(word1,word2,x,y+1,dp)})+1;
    }
    
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size(),vector<int>(word2.size()));
        return solve(word1,word2,0,0,dp);
    }
};