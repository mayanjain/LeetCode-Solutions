class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=INT_MIN,j=0,cur=1,x=INT_MIN;
        nums.push_back(0);
        for(int i=0 ; i<nums.size() ; i++){
            if(nums[i]==0){
                while(j<i){
                    ans=max(ans,cur);
                    cur/=nums[j++];
                }
                j++;
                if(i!=nums.size()-1)ans=max(0,ans);
            }
            else{
                cur*=nums[i];
                ans=max(ans,cur);
            }
        }
        return ans;
    }
};