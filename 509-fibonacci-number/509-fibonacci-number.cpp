class Solution {
public:
    int fib(int n) {
        if(n<2)return n;
        int prev=1,last=0,cur;
        for(int i=2 ; i<=n ; i++){
            cur=prev+last;
            last=prev;
            prev=cur;
        }
        return cur;
    }
};