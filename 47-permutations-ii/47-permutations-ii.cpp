class Solution {
public:
    vector<vector<int>> ans;
    
    void solve(vector<int>& nums,int i){
        if(i==nums.size()){
            ans.push_back(nums);
            return;
        }
        set<int> st;
        for(int j=i ; j<nums.size() ; j++){
            if(st.count(nums[j]))continue;
            swap(nums[i],nums[j]);
            solve(nums,i+1);
            swap(nums[i],nums[j]);
            st.insert(nums[j]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        solve(nums,0);
        return ans;
    }
};