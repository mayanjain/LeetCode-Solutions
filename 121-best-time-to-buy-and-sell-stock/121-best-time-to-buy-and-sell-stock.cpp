class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0,mn=prices[0];
        for(int i=0 ; i<prices.size() ; i++){
            mn=min(prices[i],mn);
            ans=max(ans,prices[i]-mn);
        }
        return ans;
    }
};