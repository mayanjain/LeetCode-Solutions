class Solution {
public:
    vector<int> dp;
    
    bool solve(vector<int>& nums,int i){
        if(i>=nums.size())return true;
        if(dp[i]!=-1)return dp[i];
        int p1=0,p2=0,p3=0,n=nums.size();
        if(i+1<n){
            p1=(nums[i]==nums[i+1]);
        }
        if(i+2<n){
            p2=(p1&&nums[i+2]==nums[i+1]);
            p3=(nums[i]==nums[i+1]-1 && nums[i]==nums[i+2]-2);
        }
        return dp[i]=(p1&&solve(nums,i+2))||((p2||p3)&&solve(nums,i+3));
    }
    
    bool validPartition(vector<int>& nums) {
        dp=vector<int>(nums.size(),-1);
        return solve(nums,0);
    }
};