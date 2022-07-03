class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        vector<int> higher(nums.size(),1),lower(nums.size(),1);
        int ans=1;
        for(int i=1 ; i<nums.size() ; i++){
            for(int j=i-1 ; j>=0 ; j--){
                if(nums[j]<nums[i])higher[i]=max(higher[i],lower[j]+1);
                if(nums[j]>nums[i])lower[i]=max(lower[i],higher[j]+1);
            }
            ans=max({ans,higher[i],lower[i]});
        }
        return ans;
    }
};