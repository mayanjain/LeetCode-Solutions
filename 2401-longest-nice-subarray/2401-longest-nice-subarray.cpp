class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int st=0,ans=1,orr=0;
        for(int i=0 ; i<nums.size() ; i++){
            while((orr&nums[i])){
                orr^=nums[st++];
            }
            orr|=nums[i];
            ans=max(ans,i-st+1);
        }
        return ans;
    }
};