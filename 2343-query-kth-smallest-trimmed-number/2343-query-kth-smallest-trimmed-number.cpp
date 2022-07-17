class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        for(auto& q:queries){
            int k=q[0],sz=q[1];
            set<pair<string,int>> st;
            for(int i=0 ; i<nums.size() ; i++){
                st.insert({nums[i].substr(nums[i].size()-sz),i});
                if(st.size()>k){
                    auto it=st.end();
                    st.erase(--it);
                }
            }
            auto it=--st.end();
            ans.push_back(it->second);
        }
        return ans;
    }
};