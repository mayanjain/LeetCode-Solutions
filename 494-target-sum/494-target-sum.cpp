class Solution {
public:
    int ans=0;
    
    void solve(vector<int>& nums,int pos,int target){
        if(pos==nums.size()){
            if(!target)ans++;
            return;
        }
        solve(nums,pos+1,target-nums[pos]);
        solve(nums,pos+1,target+nums[pos]);
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        solve(nums,0,target);
        return ans;
    }
};