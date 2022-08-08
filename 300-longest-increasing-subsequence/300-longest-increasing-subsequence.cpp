class Solution {
public:
    
    int lengthOfLIS(vector<int>& nums) {
        int ans=0;
        vector<int> v;
        for(auto& i:nums){
            auto it=lower_bound(v.begin(),v.end(),i);
            if(it==v.end())v.push_back(i);
            else *it=i;
            ans=max(ans,int(v.size()));
        }
        return ans;
    }
};