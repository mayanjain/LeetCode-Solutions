class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        vector<int> dp(t.size(),1e7);
        dp[0]=t[0][0];
        for(int i=1 ; i<t.size() ; i++){
            for(int j=i; j>=0 ; j--){
                if(j){
                    dp[j]=min(dp[j],dp[j-1])+t[i][j];
                }
                else dp[j]+=t[i][j];
            }
        }
        int ans=INT_MAX;
        for(auto& i:dp)ans=min(ans,i);
        return ans;
    }
};