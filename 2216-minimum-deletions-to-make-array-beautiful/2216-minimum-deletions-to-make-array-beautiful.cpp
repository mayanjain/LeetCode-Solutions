class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int ans=0,n=nums.size();
        for(int i=0 ; i<n-1 ; i+=2){
            if(nums[i]==nums[i+1]){
                ans++;i--;
            }
        }
        if((n-ans)%2)ans++;
        return ans;
    }
};