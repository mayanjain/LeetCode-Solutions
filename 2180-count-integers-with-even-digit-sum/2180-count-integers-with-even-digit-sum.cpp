class Solution {
public:
    int countEven(int num) {
        int ans=0;
        for(int i=1 ; i<=num ; i++){
            int cur=i;
            int sum=0;
            while(cur){
                sum+=cur%10;
                cur/=10;
            }
            if(sum%2==0)ans++;
        }
        return ans;
    }
};