class Solution {
public:
    vector<int> recoverArray(vector<int>& nums) {
        set<int> st;
        sort(nums.begin(),nums.end());
        unordered_map<int,int> cnt;
        for(auto& i:nums)cnt[i]++;
        for(int i=1 ; i<nums.size() ; i++){
            if(nums[i]==nums[0])continue;
            if((nums[i]-nums[0])%2==0)st.insert(nums[i]-nums[0]);
        }
        vector<int> ans;
        unordered_map<int,int> mp;
        for(auto& dif:st){
            mp=cnt;
            for(auto& i:nums){
                if(mp[i] && mp[i+dif]){
                    mp[i]--;
                    mp[i+dif]--;
                    ans.push_back(i+dif/2);
                }
            }
            if(ans.size()==nums.size()/2)return ans;
            ans.clear();
        }
        return ans;
    }
};