class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        int even=0;
        for(auto& i:nums){
            if(i%2==0)even+=i;
        }
        for(auto& q:queries){
            int index=q[1],val=q[0];
            if(nums[index]%2==0){
                if(val%2)even-=nums[index];
                else even+=val;
                nums[index]+=val;
            }
            else{
                nums[index]+=val;
                if(val%2)even+=nums[index];
            }
            ans.push_back(even);
        }
        return ans;
    }
};