class Solution {
public:
    
    int calculate(string s) {
        int ans=0,pre=0;
        stringstream ss(s);
        char sign='+';
        int num;
        while(ss>>num){
            if(sign=='+'){
                ans+=pre;
                pre=num;
            }
            if(sign=='-'){
                ans+=pre;
                pre=-num;
            }
            if(sign=='*'){
                pre*=num;
            }
            if(sign=='/'){
                pre/=num;
            }
            ss>>sign;
        }
        ans+=pre;
        return ans;
    }
};