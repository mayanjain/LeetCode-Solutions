class Solution {
public:
    vector<vector<int>> dp;
    
    int solve(string& word1,string& word2,int i,int j){
        int m=word1.size(),n=word2.size();
        if(m==i && n==j){
            return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=INT_MAX;
        if(word1[i]==word2[j])ans=solve(word1,word2,i+1,j+1);
        else{
            if(m!=i)ans=1+solve(word1,word2,i+1,j);
            if(n!=j)ans=min(ans,1+solve(word1,word2,i,j+1));
        }
        return dp[i][j]=ans;
    }
    
    int minDistance(string word1, string word2) {
        int m=word1.size(),n=word2.size();
        dp = vector<vector<int>> (m+1,vector<int>(n+1,-1));
        return solve(word1,word2,0,0);
    }
};