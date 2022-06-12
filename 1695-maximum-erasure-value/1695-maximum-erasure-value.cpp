class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int> mp;
        int ans=0,st=0,sum=0;
        for(int i=0 ; i<nums.size() ; i++){
            sum+=nums[i];
            while(mp[nums[i]]){
                sum-=nums[st];
                mp[nums[st++]]--;
            }
            mp[nums[i]]++;
            ans=max(ans,sum);
        }
        return ans;
    }
};