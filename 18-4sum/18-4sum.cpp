class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        set<vector<int>> st;
        vector<vector<int>> ans;
        int n=nums.size();
        for(int i=0 ; i<n ; i++){
            for(int j=i+1 ; j<n-2 ; j++){
                int req=target-(nums[i]+nums[j]);
                int k=j+1;
                for(int f=n-1 ; f>k ; f--){
                    while(k<f && nums[f]+nums[k]<req){
                        k++;
                    }
                    if(k!=f && nums[f]+nums[k]==req){
                        st.insert({nums[i],nums[k],nums[j],nums[f]});
                        // ans.push_back({nums[i],nums[k],nums[j],nums[f]});
                    }
                }
            }
        }
        for(auto& i:st)ans.push_back(i);
        return ans;
    }
};