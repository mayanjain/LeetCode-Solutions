class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cur=0,index=0,last=nums[0];
        for(int i=0 ; i<nums.size() ; i++){
            if(nums[i]==last)cur++;
            else cur=1;
            if(cur<=2)nums[index++]=nums[i];
            last=nums[i];
        }
        return index;
    }
};