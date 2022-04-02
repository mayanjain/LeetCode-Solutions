class Solution {
public:
    bool solvin(string s){
        int l=0,r=s.size()-1;
        while(l<r){
            if(s[l++]!=s[r--])return 0;
        }
        return 1;
    }
    
    bool validPalindrome(string s) {
        int l=0,r=s.size()-1;
        while(l<r){
            if(s[l]!=s[r]){
                if(solvin(s.substr(0,l)+s.substr(l+1)))return 1;
                if(solvin(s.substr(0,r)+s.substr(r+1)))return 1;
                return 0;
            }
            l++;r--;
        }
        return 1;
    }
};