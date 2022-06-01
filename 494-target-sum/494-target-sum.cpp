class Solution {
public:
    
    int solve(vector<int>& nums,int pos,int target,vector<vector<int>>& mp){
        if(pos==nums.size()){
            return !target;
        }
        if(mp[pos][target+3000]!=-1)return mp[pos][target+3000];
        int ans=0;
        ans+=solve(nums,pos+1,target-nums[pos],mp);
        ans+=solve(nums,pos+1,target+nums[pos],mp);
        return mp[pos][target+3000]=ans;        
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<vector<int>> mp(21,vector<int>(7005,-1));
        return solve(nums,0,target,mp);        
    }
};