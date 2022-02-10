class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0]++;
        int sum=0,ans=0;
        for(auto& i:nums){
            sum+=i;
            if(mp.count(sum-k))ans+=mp[sum-k];
            mp[sum]++;
        }
        return ans;
    }
};