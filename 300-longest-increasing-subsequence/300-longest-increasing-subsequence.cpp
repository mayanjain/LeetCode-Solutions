class Solution {
public:
    vector<int> mp;
    
    int solve(vector<int>& nums,int last,int pos){
        if(pos==nums.size()){
            return 0;
        }
        if(mp[last+1]!=-1)return mp[last+1];
        int cur=0;
        if(last==-1 || nums[pos]>nums[last]){
            cur=1+solve(nums,pos,pos+1);
        }
        cur=max(cur,solve(nums,last,pos+1));
        return mp[last+1]=cur;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        mp.resize(nums.size()+1,-1);
        return solve(nums,-1,0);
    }
};