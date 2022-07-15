class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0 ; i<n ; i++){
            if(i && nums[i]==nums[i-1])continue;
            int j=i+1,k=n-1,target=-nums[i];
            while(j<k){
                if(nums[j]+nums[k]>target)k--;
                else if(nums[j]+nums[k]<target)j++;
                else{
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++,k--;
                    while(j<k && nums[j]==nums[j-1])j++;
                    while(j<k && nums[k]==nums[k+1])k--;
                }
            }
        }
        return ans;
    }
};