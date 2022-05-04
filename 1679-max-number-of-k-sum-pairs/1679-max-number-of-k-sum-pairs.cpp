class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        map<int,int> mp;
        int ans=0;
        for(auto& i:nums){
            if(mp.count(k-i) && mp[k-i]>0){
                ans++;
                mp[k-i]--;
            }
            else mp[i]++;
        }
        return ans;
    }
};