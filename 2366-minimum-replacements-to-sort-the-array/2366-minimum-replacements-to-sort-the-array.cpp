class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long ans=0,n=nums.size();
        for(int i=n-2 ; i>=0 ; i--){
            int cur=nums[i]/nums[i+1];
            if(nums[i]%nums[i+1]){
                cur++;
            }
            nums[i]=nums[i]/cur;
            ans+=cur-1;
        }
        return ans;
    }
};