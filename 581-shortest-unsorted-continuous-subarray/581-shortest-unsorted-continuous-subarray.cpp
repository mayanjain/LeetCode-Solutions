class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        auto z=nums;
        sort(z.begin(),z.end());
        int st=-1,end=-1;
        for(int i=0 ; i<nums.size() ; i++){
            if(z[i]!=nums[i]){
                if(st==-1)st=i;
                end=i;
            }
        }
        if(st==-1)st++;
        return end-st+1;
    }
};