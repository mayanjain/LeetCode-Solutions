class Solution {
public:
    int minOperations(vector<int>& v, vector<int>& nums) {
        int gcd=nums[0];
        for(int i=1 ; i<nums.size() ; i++){
            gcd=__gcd(gcd,nums[i]);
        }
        int ans=INT_MAX;
        for(auto& i:v){
            if(gcd%i==0)ans=min(ans,i);
        }
        int x=0;
        for(auto& i:v){
            if(i<ans)x++;
        }
        return x==v.size()?-1:x;
    }
};