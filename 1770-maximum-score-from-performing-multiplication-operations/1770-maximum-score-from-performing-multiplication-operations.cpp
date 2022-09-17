class Solution {
public:
    int dp[1001][1001]={};
    
    int solve(vector<int>& nums,vector<int>& mlt,int op,int l){
        if(op==mlt.size())return 0;
        if(dp[l][op]==INT_MIN){
            int r=nums.size()-1-(op-l);
            dp[l][op]=max(nums[l]*mlt[op]+solve(nums,mlt,op+1,l+1),nums[r]*mlt[op]+solve(nums,mlt,op+1,l));
        }
        return dp[l][op];
    }
    
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        for(auto& i:dp)for(auto& j:i)j=INT_MIN;
        return solve(nums,multipliers,0,0);
    }
};