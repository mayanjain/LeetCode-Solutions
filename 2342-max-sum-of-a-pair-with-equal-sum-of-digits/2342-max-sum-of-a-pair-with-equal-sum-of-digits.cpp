class Solution {
public:
    int maximumSum(vector<int>& nums) {
        map<int,multiset<int>> mp;
        int ans=-1;
        for(auto& i:nums){
            int cur=0;
            int f=i;
            while(f){
                cur+=f%10;
                f/=10;
            }
            mp[cur].insert(i);
            if(mp[cur].size()>2)mp[cur].erase(mp[cur].begin());
        }
        for(auto& i:mp){
            if(i.second.size()==2){
                auto it=i.second.begin();
                ans=max(ans,(*it++)+(*it));
            }
        }
        return ans;
    }
};