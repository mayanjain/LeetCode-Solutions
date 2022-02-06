class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> odd,even;
        for(int i=0 ; i<nums.size() ; i++){
            if(i%2)odd.push_back(nums[i]);
            else even.push_back(nums[i]);
        }
        sort(odd.begin(),odd.end(),greater<int>());
        sort(even.begin(),even.end());
        int o=0,e=0;
        for(int i=0 ; i<nums.size() ; i++){
            if(i%2)nums[i]=odd[o++];
            else nums[i]=even[e++];
        }
        return nums;
    }
};