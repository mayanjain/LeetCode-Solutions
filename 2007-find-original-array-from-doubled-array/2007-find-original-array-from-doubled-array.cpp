class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        map<int,int> mp;
        sort(changed.rbegin(),changed.rend());
        for(auto& i:changed)mp[i]++;
        vector<int> ans;
        for(auto& i:changed){
            if(mp[i]){
                mp[i]--;
                if(i%2==0 && mp[i/2]>0){
                    mp[i/2]--;
                    ans.push_back(i/2);
                }
                else return {};
            }
        }
        return ans;
    }
};