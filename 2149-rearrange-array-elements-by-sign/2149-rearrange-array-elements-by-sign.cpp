class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos;
        vector<int> neg;
        for(auto& i:nums){
            (i>0?pos:neg).push_back(i);
        }
        int j=0;
        for(int i=0 ; i<nums.size() ; i+=2){
            nums[i]=pos[j];
            nums[i+1]=neg[j++];
        }
        return nums;
    }
};