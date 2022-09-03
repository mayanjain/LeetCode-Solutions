class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0,n=nums.size(),high=n-1;
        while(low<high){
            int mid=(low+high)/2;
            if(nums[mid]>nums[high])low=mid+1;
            else high=mid;
        }
        int rot=low;
        low=0,high=n-1;
        while(low<=high){
            int mid=(low+high)/2,upmid=(mid+rot)%n;
            if(nums[upmid]==target)return upmid;
            if(nums[upmid]>target)high=mid-1;
            else low=mid+1;
        }
        return -1;
    }
};