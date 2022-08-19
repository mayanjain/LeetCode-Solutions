class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto& i:nums)mp[i]++;
        for(int i=0 ; i<nums.size() ; i++){
            int cur=0,val=nums[i];
            while(mp[val]>mp[val-1]){
                cur++;
                mp[val++]--;
            }
            if(cur==1 || cur==2)return false;
        }
        return true;
    }
};