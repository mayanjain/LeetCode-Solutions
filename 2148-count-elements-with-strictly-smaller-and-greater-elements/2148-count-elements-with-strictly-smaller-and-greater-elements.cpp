class Solution {
public:
    int countElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0;
        for(auto& i:nums){
            if(i!=nums[0] && i!=nums[nums.size()-1])ans++;
        }
        return ans;
    }
};