class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());
        int ans=0;
        for(auto& i:nums){
            int k=i,cur=0;
            while(st.count(k)){
                st.erase(k++);
                cur++;
            }
            k=i-1;
            while(st.count(k)){
                st.erase(k--);
                cur++;
            }
            ans=max(ans,cur);
        }
        return ans;
    }
};