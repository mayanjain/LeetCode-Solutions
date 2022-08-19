class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long ans=0,n=nums.size();
        for(int i=n-2 ; i>=0 ; i--){
            if(nums[i]>nums[i+1]){
                int cur=(nums[i]/nums[i+1]),z=nums[i]%nums[i+1];
                nums[i+1]--;
                while(nums[i+1] && nums[i]/nums[i+1]==cur && z){
                    nums[i+1]--;
                }
                nums[i+1]++;
                ans+=cur-1;
                if(nums[i]%nums[i+1]){
                    ans++;
                    nums[i]=nums[i+1]-1;
                }
                else nums[i]=nums[i+1];
            }
        }
        return ans;
    }
};