class Solution {
public:
    vector<vector<int>> dp;
    
    int solve(vector<int>& a,vector<int>& b,int pos,int state){
        if(pos==a.size())return 0;
        if(dp[pos][state])return dp[pos][state];
        dp[pos][state]=solve(a,b,pos+1,state);
        if(state<2)dp[pos][state]=max(dp[pos][state],solve(a,b,pos+1,state+1));
        return dp[pos][state]+=(state==1?b[pos]:a[pos]);
    }
    
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        dp=vector<vector<int>>(nums1.size(),vector<int>(3));
        int cur=max(solve(nums1,nums2,0,0),solve(nums1,nums2,0,1));
        dp=vector<vector<int>>(nums1.size(),vector<int>(3));
        int cur2=max(solve(nums2,nums1,0,0),solve(nums2,nums1,0,1));
        return max(cur,cur2);
    }
};