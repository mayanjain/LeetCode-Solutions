class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mx=0,cur=0,ans=1;
        for(auto& i:nums)mx=max(i,mx);
        for(auto& i:nums){
            if((i&mx)==mx)cur++;
            else cur=0;
            ans=max(ans,cur);
        }
        return ans;
    }
};