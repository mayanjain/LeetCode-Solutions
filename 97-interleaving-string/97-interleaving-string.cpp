class Solution {
public:
    vector<vector<int>> dp;
    
    bool check(string& s1,string& s2,int i,int j,string& s3){
        int m=s1.size(),n=s2.size(),k=s3.size();
        if(m+n!=k)return false;
        if(i+j==k)return true;
        if(dp[i][j]!=-1)return dp[i][j];
        if(i<m && s1[i]==s3[i+j] && check(s1,s2,i+1,j,s3))return dp[i][j]=true;
        if(j<n && s2[j]==s3[i+j] && check(s1,s2,i,j+1,s3))return dp[i][j]=true;
        return dp[i][j]=false;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        dp=vector<vector<int>>(s1.size()+1,vector<int>(s2.size()+1,-1));
        return check(s1,s2,0,0,s3);
    }
};