class Solution {
public:
    string addBinary(string a, string b) {
        int r=0,i=a.size()-1,j=b.size()-1,cur=0;
        string ans="";
        while(r || i>=0 || j>=0){
            cur=r;
            if(i>=0)cur+=a[i]-'0';
            if(j>=0)cur+=b[j]-'0';
            if(cur==3){
                r=1;
                ans+='1';
            }
            else if(cur==2){
                r=1;
                ans+='0';
            }
            else if(cur==1){
                r=0;
                ans+='1';
            }
            else{
                ans+='0';
            }
            i--;j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};