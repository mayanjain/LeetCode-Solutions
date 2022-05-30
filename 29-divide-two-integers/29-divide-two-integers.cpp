class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN && divisor==-1)return INT_MAX;
        long divi=abs(dividend),dis=abs(divisor),ans=0;
        long sign=divisor>0 ^ dividend>0 ? -1:1;
        while(divi>=dis){
            long temp=dis,m=1;
            while((temp<<1)<=divi){
                temp<<=1;
                m<<=1;
            }
            divi-=temp;
            ans+=m;
        }
        return sign*ans;
    }
};