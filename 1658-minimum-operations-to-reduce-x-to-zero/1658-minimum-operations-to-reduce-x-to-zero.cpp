class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum=-x,n=nums.size();
        for(auto& i:nums)sum+=i;
        // cout<<sum<<" ";
        int cur=0,ans=INT_MAX,st=0;
        for(int i=0 ; i<n ; i++){
            cur+=nums[i];
            while(st<=i && cur>sum){
                cur-=nums[st++];
            }
            if(cur==sum){
                ans=min(ans,n-(i-st+1));
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};