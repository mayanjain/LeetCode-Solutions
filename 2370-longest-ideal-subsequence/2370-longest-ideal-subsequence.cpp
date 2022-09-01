class Solution {
public:
    vector<vector<int>> dp;
    
    int solve(string& s,int i,char last,int k){
        int n=s.size();
        if(n==i)return 0;
        if(dp[i][last-'a']!=-1)return dp[i][last-'a'];
        int ans=solve(s,i+1,last,k);
        if(abs(last-s[i])<=k)ans=max(ans,1+solve(s,i+1,s[i],k));
        return dp[i][last-'a']=ans;
    }
    
    int longestIdealString(string s, int k) {
        dp=vector<vector<int>>(s.size(),vector<int>(26,-1));
        int ans=0;
        for(int i=0 ; i<s.size() ; i++){
            ans=max(ans,solve(s,i,s[i],k));
        }
        return ans;
    }
};