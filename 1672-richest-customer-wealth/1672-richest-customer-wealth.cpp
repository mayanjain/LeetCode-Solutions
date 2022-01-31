class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans=0;
        for(auto& i:accounts){
            int cur=0;
            for(auto& j:i){
                cur+=j;
            }
            ans=max(ans,cur);
        }
        return ans;
    }
};