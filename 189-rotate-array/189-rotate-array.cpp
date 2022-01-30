class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k%=nums.size();
        k=nums.size()-k;
        vector<int> ans;
        for(int i=0 ; i<nums.size() ; i++){
            ans.push_back(nums[k%nums.size()]);
            k++;
        }
        for(int i=0 ; i<nums.size() ; i++)nums[i]=ans[i];
    }
};