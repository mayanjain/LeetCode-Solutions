class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index=0;
        for(auto& n:nums){
            if(index<2 || n!=nums[index-2]){
                nums[index++]=n;
            }
        }
        return index;
    }
};