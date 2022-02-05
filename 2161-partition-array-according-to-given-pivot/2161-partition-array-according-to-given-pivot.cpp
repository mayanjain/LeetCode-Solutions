class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int less=0,equal=0;
        for(auto& i:nums){
            if(i<pivot)less++;
            if(i==pivot)equal++;
        }
        int less_pos=0,high_pos=less;
        vector<int> ans(nums.size());
        for(int i=less ; i<less+equal ; i++){
            ans[i]=pivot;
            high_pos++;
        }
        for(auto& i:nums){
            if(i<pivot)ans[less_pos++]=i;
            else if(i>pivot)ans[high_pos++]=i;
        }
        return ans;
    }
};