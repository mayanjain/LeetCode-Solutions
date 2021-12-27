class Solution {
public:
    int findComplement(int num) {
        int ans=0;
        for(int i=0 ; i<32 && num ; i++){
            if((num&1)==0){
                ans+=(1<<i);
            }
            num>>=1;
        }
        return ans;
    }
};