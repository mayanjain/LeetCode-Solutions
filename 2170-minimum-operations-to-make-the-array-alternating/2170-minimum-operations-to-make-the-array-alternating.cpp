class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int,int> odd,even;
        int mx_odd=0,smx_odd=0,mx_even=0,smx_even=0;
        for(int i=0 ; i<nums.size() ; i++){
            if(i&1){
                int c=++odd[nums[i]];
                if(c>odd[mx_odd]){
                    smx_odd=mx_odd;
                    mx_odd=nums[i];
                }
                else if(c>odd[smx_odd] && nums[i]!=mx_odd){
                    smx_odd=nums[i];
                }
            }
            else{
                int c=++even[nums[i]];
                if(c>even[mx_even]){
                    smx_even=mx_even;
                    mx_even=nums[i];
                }
                else if(c>odd[smx_even] && nums[i]!=mx_even){
                    smx_even=nums[i];
                }
            }
        }
        if(mx_odd!=mx_even){
            return nums.size()-odd[mx_odd]-even[mx_even];
        }
        return min(nums.size()-odd[mx_odd]-even[smx_even],nums.size()-odd[smx_odd]-even[mx_even]);
    }
};