class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n=s.size();
        vector<int> closing(n+1);
        for(int i=n-1 ; i>=0 ; i--){
            closing[i]=closing[i+1];
            if(s[i]==')')closing[i]++;
        }
        string ans="";
        int op=0;
        for(int i=0 ; i<n ; i++){
            if(s[i]=='('){
                if(closing[i]>op){
                    ans+=s[i];
                    op++;
                }
            }
            else if(s[i]==')'){
                if(op){
                    ans+=s[i];
                    op--;
                }
            }
            else ans+=s[i];
        }   
        return ans;
    }
};