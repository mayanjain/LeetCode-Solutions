class Solution {
public:
    vector<vector<int>> ans;
    
    void solve(vector<int>& nums,int i){
        if(i+1==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int j=i ; j<nums.size() ; j++){
            if(j>i && nums[i]==nums[j])continue;
            swap(nums[j],nums[i]);
            solve(nums,i+1);
        }
        for(int j=nums.size()-1 ; j>i ; j--){
            swap(nums[j],nums[i]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        solve(nums,0);
        return ans;
    }
};