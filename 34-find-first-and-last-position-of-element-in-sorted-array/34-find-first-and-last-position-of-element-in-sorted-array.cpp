class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto it=lower_bound(nums.begin(),nums.end(),target)-nums.begin(),it2=upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        if(it==nums.size())return {-1,-1};
        if(nums[it]==target)return {int(it),int(it2-1)};
        return {-1,-1};
    }
};