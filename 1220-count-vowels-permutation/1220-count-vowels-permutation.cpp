class Solution {
public:
    const int mod=1e9+7;
    map<char,string> mp; 
    vector<vector<int>> dp;
    
    int solve(int n,char last){
        if(n==0)return 1;
        long ans=0;
        if(dp[n][last-'a']!=-1)return dp[n][last-'a'];
        for(auto& i:mp[last]){
            ans+=solve(n-1,i);
        }
        return dp[n][last-'a']=ans%mod;
    }
    
    int countVowelPermutation(int n) {
        mp['x']="aeiou";
        mp['a']="e";
        mp['e']="ai";
        mp['i']="aeou";
        mp['o']="iu";
        mp['u']="a";
        dp=vector<vector<int>>(n+1,vector<int>(26,-1));
        return solve(n,'x');
    }
};