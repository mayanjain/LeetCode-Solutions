class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        map<int,int> mp;
        for(auto& i:nums)mp[i]++;
        vector<int> ans;
        for(auto& i:mp){
            int v=i.first;
            if(mp[v]>1 || mp.count(v-1) || mp.count(v+1))continue;
            ans.push_back(v);
        }
        return ans;
    }
};