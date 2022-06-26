class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n=nums.size(),ans=0,sum=0,mx=0,ls=0,nk=n-k;
        for(int i=0 ; i<n ; i++){
            sum+=nums[i];
        }
        if(!nk)return sum;
        for(int i=0 ; i<n ; i++){
            sum-=nums[i];
            if(i>=nk-1){
                ans=max(ans,sum);
                sum+=nums[ls++];
            }
        }
        return ans;
    }
};