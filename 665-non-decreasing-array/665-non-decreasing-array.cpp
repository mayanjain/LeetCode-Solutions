class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int ch=0;
        for(int i=1 ; i<nums.size() ; i++){
            if(nums[i]<nums[i-1]){
                if(i!=1){
                    if(nums[i-2]<=nums[i]){
                        nums[i-1]=nums[i-2];
                    }
                    else nums[i]=nums[i-1];
                }
                else{
                    nums[0]=nums[1];
                }
                ch++;
            }
        }
        return ch<2;
    }
};