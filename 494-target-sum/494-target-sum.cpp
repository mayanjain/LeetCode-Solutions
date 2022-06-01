class Solution {
public:
    map<pair<int,int>,int> mp;
    
    int solve(vector<int>& nums,int pos,int target){
        if(pos==nums.size()){
            return !target;
        }
        if(mp.count({pos,target}))return mp[{pos,target}];
        int ans=0;
        ans+=solve(nums,pos+1,target-nums[pos]);
        ans+=solve(nums,pos+1,target+nums[pos]);
        return mp[{pos,target}]=ans;        
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums,0,target);        
    }
};