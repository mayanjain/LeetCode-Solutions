class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int left=0,right=nums.size()-1,max=INT_MIN,min=INT_MAX,st=-1,ed=-2;
        while(right>=0){
            if(nums[left]<max){
                ed=left;
            }
            else max=nums[left];
            if(nums[right]>min){
                st=right;
            }
            else min=nums[right];
            left++;right--;
        }
        return ed-st+1;
    }
};