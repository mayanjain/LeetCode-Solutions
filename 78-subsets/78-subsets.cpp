class Solution {
public:
    vector<vector<int>> ans;
    
    void solve(vector<int>& nums,vector<int>& cur,int p){
        if(p==nums.size()){
            ans.push_back(cur);
            return;
        }
        solve(nums,cur,p+1);
        cur.push_back(nums[p]);
        solve(nums,cur,p+1);
        cur.pop_back();
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> cur;
        solve(nums,cur,0);
        return ans;
    }
};