class Solution {
public:
    int minMoves(int target, int mx) {
        int ans=0;
        while(target!=1){
            if(mx==0){
                ans+=(target-2);
                target=1;
            }
            else if(target%2){
                target--;
            }
            else{
                target/=2;
                mx--;
            }
            ans++;
        }
        return ans;
    }
};