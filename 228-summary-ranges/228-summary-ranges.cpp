class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int n=nums.size();
        if(n==0)return ans;
        for(int i=0; i<n ; i++){
            long j=i,cur=nums[i];
            while(j<n && nums[j]==cur){
                j++;cur++;
            }
            j--;
            if(j>i)ans.push_back(to_string(nums[i])+"->"+to_string(nums[j]));
            else ans.push_back(to_string(nums[i]));
            i=j;
        }
        return ans;
    }
};