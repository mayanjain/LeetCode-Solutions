class Solution {
public:
    int mySqrt(int x) {
        long low=0,high=1e5;
        while(low<high-1){
            long mid=(low+high)/2;
            if(mid*mid>x){
                high=mid-1;
            }
            else low=mid;
        }
        if(high*high>x)return low;
        return high;
    }
};