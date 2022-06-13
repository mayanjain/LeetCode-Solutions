class Solution {
public:
    vector<vector<int>> dp;
    
    int solve(vector<vector<int>>& triangle,int row,int col){
        if(row==triangle.size())return 0;
        if(dp[row][col]!=-1)return dp[row][col];
        return dp[row][col]= min(solve(triangle,row+1,col),solve(triangle,row+1,col+1))+triangle[row][col];
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        dp=vector<vector<int>> (n,vector<int>(n,-1));
        return solve(triangle,0,0);
    }
};