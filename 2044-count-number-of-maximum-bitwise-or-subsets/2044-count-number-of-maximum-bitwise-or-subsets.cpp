class Solution {
public:
    int ans=0;
    
    void solve(vector<int>& nums,int i,int cur,int x){
        if(i==nums.size()){
            if(cur==x)ans++;
            return;
        }
        solve(nums,i+1,cur|nums[i],x);
        solve(nums,i+1,cur,x);
    }
    
    int countMaxOrSubsets(vector<int>& nums) {
        auto x=0;
        for(auto& i:nums)x|=i;
        solve(nums,0,0,x);
        return ans;
    }
};