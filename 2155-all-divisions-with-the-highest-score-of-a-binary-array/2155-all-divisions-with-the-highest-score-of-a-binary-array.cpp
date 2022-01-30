class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int one=0,zero=0;
        for(auto& i:nums){
            if(i)one++;
        }
        int score=one,cur;
        vector<int> ans(1);
        for(int i=0 ; i<nums.size() ; i++){
            if(nums[i]==0)zero++;
            else one--;
            cur=zero+one;
            if(cur>score){
                ans={i+1};
                score=cur;
            }
            else if(cur==score)ans.push_back(i+1);
        }
        return ans;
    }
};