class Solution {
public:
    string solve(string& s,int st,int end){
        while(st>=0 && end<s.size() && s[st]==s[end]){
            st--;
            end++;
        }
        return s.substr(st+1,end-st-1);
    }
    
    string longestPalindrome(string s) {
        string ans="",cur;
        for(int i=0 ; i<s.size() ; i++){
            cur=solve(s,i-1,i+1);
            if(cur.size()>ans.size()){
                ans=cur;
            }
            cur=solve(s,i,i+1);
            if(cur.size()>ans.size()){
                ans=cur;
            }
        }
        return ans;
    }
};