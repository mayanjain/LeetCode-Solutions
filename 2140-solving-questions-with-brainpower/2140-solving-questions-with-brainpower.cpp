class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<long long> dp(n);
        for(int i=n-1 ; i>=0 ; i--){
            dp[i]=questions[i][0];
            int next=questions[i][1]+i+1;
            if(next<n)dp[i]+=dp[next];
            if(i<n-1)dp[i]=max(dp[i],dp[i+1]);
        }
        return dp[0];
    }
};
