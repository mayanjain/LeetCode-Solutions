class Solution {
public:
    string reverseWords(string s) {
        for(int i=0 ; i<s.size() ; i++){
            int x=i;
            while(x<s.size() && s[x]!=' ')x++;
            reverse(s.begin()+i,s.begin()+x);
            i=x;
        }
        return s;
    }
};