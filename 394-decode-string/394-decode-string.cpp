class Solution {
public:
    int i=0;
    
    string decodeString(string& s) {
        string ans="";
        while(i<s.size() && s[i]!=']'){
            if(s[i]<'0' || s[i]>'9'){
                ans+=s[i++];
            }
            else{
                int rep=0;
                while(s[i]>='0' && s[i]<='9'){
                    rep=rep*10+s[i++]-'0';
                }
                i++;
                string cur=decodeString(s);
                i++;
                while(rep-->0){
                    ans+=cur;
                }
            }
        }
        return ans;
    }
};