class Solution {
public:
    int myAtoi(string s) {
        if(s.size()==0)return 0;
        long i=0,sign=1,ans=0;
        while(s[i]==' ')i++;
        if(s[i]=='-' || s[i]=='+'){
            sign=(s[i++]=='-')?-1:1;
        }
        while(s[i]>='0' && s[i]<='9'){
            ans=ans*10+s[i++]-'0';
            if(ans*sign>=INT_MAX)return INT_MAX;
            if(ans*sign<=INT_MIN)return INT_MIN;
        }
        return sign*ans;
    }
};