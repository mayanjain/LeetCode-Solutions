class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        vector<vector<pair<string,int>>> v(nums[0].size());
        for(int sz=0 ; sz<nums[0].size() ; sz++){
            for(int i=0 ; i<nums.size() ; i++){
                v[sz].push_back({nums[i].substr(sz),i});
                // cout<<nums[i].substr(sz)<<" ";
            }
            sort(v[sz].begin(),v[sz].end());
        }
        for(auto& q:queries){
            int k=q[0],sz=q[1];
            ans.push_back(v[nums[0].size()-sz][k-1].second);
        }
        return ans;
    }
};