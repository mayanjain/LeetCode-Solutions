class Solution {
public:
    vector<int> dp;
    
    int solve(vector<int>& nums,int target){
        if(target<0)return 0;
        if(!target)return 1;
        if(dp[target]!=-1)return dp[target];
        int ans=0;
        for(int i=0 ; i<nums.size() ; i++){
            ans+=solve(nums,target-nums[i]);
        }
        return dp[target]=ans;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        dp = vector<int>(target+1,-1);
        return solve(nums,target);
    }
};