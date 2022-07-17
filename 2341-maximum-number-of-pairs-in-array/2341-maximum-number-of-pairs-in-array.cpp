class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        int cur=1;
        sort(nums.begin(),nums.end());
        vector<int> ans(2);
        for(int i=1 ; i<nums.size(); i++){
            if(nums[i]==nums[i-1]){
                cur++;
            }
            else{
                cur=1;
            }
            ans[0]+=(cur%2==0);
        }
        ans[1]=nums.size()-ans[0]*2;
        return ans;
    }
};