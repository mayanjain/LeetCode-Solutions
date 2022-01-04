class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0)return 1;
        int ans=0;
        for(int i=0 ; i<32 && n ; i++){
            if((n&1)==0){
                ans|=(1<<i);
            }
            n>>=1;
        }
        return ans;
    }
};