class Solution {
public:
    string pushDominoes(string s) {
        s="L"+s+"R";
        string ans="";
        int n=s.size();
        for(int i=0 ; i+1<n ; i++){
            int j=i+1;
            while(s[j]=='.')j++;
            int total=j-i-1;
            ans+=s[i];
            if(s[i]==s[j]){
                ans+=string(total,s[i]);
            }
            else if(s[i]=='L' && s[j]=='R'){
                ans+=string(total,'.');
            }
            else{
                ans+=string(total/2,s[i])+string(total%2,'.')+string(total/2,s[j]);
            }
            i=j-1;
        }
        return ans.substr(1);
    }
};