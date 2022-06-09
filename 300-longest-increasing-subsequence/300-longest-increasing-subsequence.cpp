class Solution {
public:
    vector<vector<int>> mp;
    
    int solve(vector<int>& nums,int last,int pos){
        if(pos==nums.size()){
            return 0;
        }
        if(mp[last+1][pos]!=-1)return mp[last+1][pos];
        int cur=0;
        if(last==-1 || nums[pos]>nums[last]){
            cur=1+solve(nums,pos,pos+1);
        }
        cur=max(cur,solve(nums,last,pos+1));
        return mp[last+1][pos]=cur;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        mp.resize(nums.size()+1,vector<int>(nums.size(),-1));
        return solve(nums,-1,0);
    }
};