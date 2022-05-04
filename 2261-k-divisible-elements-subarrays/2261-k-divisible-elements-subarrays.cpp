class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int n=nums.size(),count=0;
        set<vector<int>> ans;
        string cur="";
        for(int i=0 ; i<n ; i++){
            int count=0;
            vector<int> v;
            for(int j=i ; j<n ; j++){
                v.push_back(nums[j]);
                if(nums[j]%p==0)count++;
                if(count>k)break;
                ans.insert(v);
            }
        }
        return ans.size();
    }
};