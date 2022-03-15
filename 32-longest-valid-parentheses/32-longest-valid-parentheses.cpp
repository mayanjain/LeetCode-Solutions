class Solution {
public:
    int longestValidParentheses(string s) {
        int ans=0,cur=0,ls=0,n=s.size();
        for(int i=0 ; i<n ; i++){
            if(s[i]=='(')cur++;
            else cur--;
            if(cur==0)ans=max(ans,i-ls+1);
            else if(cur<0){
                ans=max(ans,i-ls);
                ls=i+1;
                cur=0;
            }
        }
        if(cur==0)ans=max(ans,n-ls);
        cur=0,ls=n-1;
        for(int i=n-1 ; i>=0 ; i--){
            if(s[i]==')')cur++;
            else cur--;
            if(cur==0)ans=max(ans,ls-i+1);
            else if(cur<0){
                ans=max(ans,ls-i);
                ls=i-1;
                cur=0;
            }
        }
        if(cur==0)ans=max(ans,ls+1);
        return ans;
    }
};