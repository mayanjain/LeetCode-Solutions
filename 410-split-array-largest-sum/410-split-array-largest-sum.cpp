class Solution {
public:
    bool canSplit(vector<int>& nums,int mid,int m){
        long cur=0;
        for(auto& i:nums){
            if(i>mid)return 0;
            if(cur+i<=mid){
                cur+=i;
            }
            else{
                m--;
                cur=i;
                if(m<0)return 0;
            }
        }
        return 1;
    }
    
    int splitArray(vector<int>& nums, int m) {
        int right=0,left=0;
        for(auto& i:nums){
            left=max(left,i);
            right+=i;
        }
        while(left<right){
            int mid=left+(right-left)/2;
            if(canSplit(nums,mid,m-1))right=mid;
            else left=mid+1;
        }
        return left;
    }
};