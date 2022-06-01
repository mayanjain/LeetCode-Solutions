class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for(auto& i:nums)sum+=i;
        target=abs(target);
        if((sum+target)%2 || target>sum)return 0;
        sum+=target;
        sum/=2;
        vector<vector<int>> dp(nums.size()+1,vector<int>(sum+1));
        for(int i=0 ; i<=nums.size() ; i++)dp[i][0]=1;
        int ans=0;
        for(int i=1 ; i<dp.size() ; i++){
            for(int j=0 ; j<=sum ; j++){
                if(nums[i-1]<=j){
                    dp[i][j]=dp[i-1][j]+dp[i-1][j-nums[i-1]];
                }
                else dp[i][j]=dp[i-1][j];
            }
        }
        return dp[nums.size()][sum];
    }
};