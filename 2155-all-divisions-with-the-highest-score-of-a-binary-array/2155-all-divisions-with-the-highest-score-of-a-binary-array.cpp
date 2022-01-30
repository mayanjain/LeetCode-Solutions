class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        vector<int> one(nums.size());
        auto zero=one;
        for(int i=0 ; i<nums.size() ; i++){
            if(nums[i])one[i]++;
            else zero[i]++;
            if(i){
                one[i]+=one[i-1];
                zero[i]+=zero[i-1];
            }
        }
        int ans=one[nums.size()-1];
        for(int i=0 ; i<nums.size() ; i++){
            ans=max(ans,one[nums.size()-1]-one[i]+zero[i]);
        }
        vector<int> res;
        if(ans==one[nums.size()-1])res.push_back(0);
        for(int i=0 ; i<nums.size() ; i++){
            if(one[nums.size()-1]-one[i]+zero[i]==ans)res.push_back(i+1);
        }
        return res;
    }
};