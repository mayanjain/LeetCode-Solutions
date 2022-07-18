class Solution {
public:
    int dp[501][501];
    
    int solve(string& word1,string& word2,int x,int y){
        int sz1=word1.size(),sz2=word2.size();
        if(y==sz2)return sz1-x;
        if(x==sz1)return sz2-y;
        if(word1[x]==word2[y])return solve(word1,word2,x+1,y+1);
        if(dp[x][y])return dp[x][y];
        return dp[x][y]=min({solve(word1,word2,x+1,y),solve(word1,word2,x+1,y+1),solve(word1,word2,x,y+1)})+1;
    }
    
    int minDistance(string word1, string word2) {
        return solve(word1,word2,0,0);
    }
};