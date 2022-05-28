class Solution {
public:
    int missingNumber(vector<int>& nums) {
        set<int> st(nums.begin(),nums.end());
        for(int i=0 ; i<=nums.size() ; i++){
            if(!st.count(i))return i;
        }
        return -1;
    }
};