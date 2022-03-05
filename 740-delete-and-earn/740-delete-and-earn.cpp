class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int,int> mp;
        for(auto& i:nums)mp[i]++;
        vector<int> v(1e4+1);
        v[1]=mp[1];
        for(int i=2 ; i<=1e4 ; i++){
            v[i]=v[i-1];
            if(mp.count(i))v[i]=max(v[i-2]+mp[i]*i,v[i]);
        }
        return v[1e4];
    }
};