class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int mn=nums[0];
        map<int,int> mp;
        for(int i=1 ; i<nums.size() ; i++)mp[nums[i]]++;
        for(int i=1 ; i<nums.size() ; i++){
            mn=min(mn,nums[i]);
            if(--mp[nums[i]]==0)mp.erase(nums[i]);
            auto it=mp.upper_bound(mn);
            if(it==mp.end())continue;
            if(it->first<nums[i] && it->first>mn)return true;
        }
        return false;
    }
};