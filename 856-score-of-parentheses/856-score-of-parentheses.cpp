class Solution {
public:
    
     double solvin(string& s,int l,int h){
        if(l>h)return 0.5;
        double ans=0;
        int ls=l,cur=0;
        for(int i=l ; i<=h ; i++){
            if(s[i]=='('){
                cur++;
            }
            else cur--;
            if(cur==0){
                ans+=2*solvin(s,ls+1,i-1);
                ls=i+1;
            }
        }
        return ans;
    }
    
    int scoreOfParentheses(string s) {
        return int(solvin(s,0,s.size()-1));
    }
};