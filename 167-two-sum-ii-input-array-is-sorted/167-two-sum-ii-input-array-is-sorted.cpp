class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mp;
        for(int i=0 ; i<nums.size() ; i++){
            if(mp.count(target-nums[i]))return {mp[target-nums[i]],i+1};
            mp[nums[i]]=i+1;
        }
        return {};
    }
};