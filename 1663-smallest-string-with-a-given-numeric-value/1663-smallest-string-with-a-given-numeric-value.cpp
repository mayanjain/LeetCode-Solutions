class Solution {
public:
    string getSmallestString(int n, int k) {
        string s(n,'a');
        k-=n;
        for(int i=n-1 ; i>=0 && k ; i--){
            int c=min(k,25);
            s[i]+=c;
            k-=c;
        }
        return s;
    }
};