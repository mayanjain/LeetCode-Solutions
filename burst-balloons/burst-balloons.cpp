class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.insert(nums.begin(),1);
        nums.insert(nums.end(),1);
        vector<vector<int>> v(nums.size(),vector<int>(nums.size()));
        for(int len=1 ; len<=n ; len++){
            for(int st=1 ; st<=n-len+1 ; st++){
                int end=st+len-1;
                int best=0;
                for(int f=st ; f<=end ; f++){
                    int coins=v[st][f-1]+v[f+1][end];
                    coins+=nums[st-1]*nums[f]*nums[end+1];
                    best=max(best,coins);
                }
                v[st][end]=best;
            }
        }
        return v[1][n];
    }
};