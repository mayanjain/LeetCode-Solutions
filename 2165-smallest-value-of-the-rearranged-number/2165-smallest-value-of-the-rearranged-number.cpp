class Solution {
public:
    long long smallestNumber(long long num) {
        bool neg=0;
        if(num<0){
            neg=1;
            num=-num;
        }
        string s=to_string(num);
        sort(s.begin(),s.end());
        if(neg){
            reverse(s.begin(),s.end());
            return -stoll(s);
        }
        int i=0;
        while(i<s.size() && s[i]=='0')i++;
        if(i!=s.size())swap(s[0],s[i]);
        return stoll(s);
    }
};