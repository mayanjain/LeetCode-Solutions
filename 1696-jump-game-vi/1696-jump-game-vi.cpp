class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n=nums.size();
        multiset<int> st;
        vector<int> dp(n);
        dp[0]=nums[0];
        st.insert(nums[0]);
        for(int i=1 ; i<n ; i++){
            auto it=st.end();
            dp[i]=nums[i]+*(--it);
            st.insert(dp[i]);
            if(st.size()>k){
                st.erase(st.lower_bound(dp[i-k]));
            }
            // cout<<dp[i]<<" ";
        }
        return dp[n-1];
    }
};