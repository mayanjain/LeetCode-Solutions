class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int ans=0;
        for(int i=0 ; i<nums.size(); i++){
            if(mp.count(nums[i])){
                if(k==0 && mp[nums[i]]==1)ans++;
                mp[nums[i]]++;
                continue;
            }
            if(mp.count(nums[i]+k))ans++;
            if(mp.count(nums[i]-k))ans++;
            mp[nums[i]]++;
        }
        return ans;
    }
};