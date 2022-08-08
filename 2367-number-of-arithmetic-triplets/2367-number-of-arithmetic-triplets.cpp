class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int ans=0,n=nums.size();
        unordered_set<int> st;
        for(auto& i:nums)st.insert(i);
        for(auto& i:nums){
            if(st.count(i+diff) && st.count(i+2*diff))ans++;
        }
        return ans;
    }
};