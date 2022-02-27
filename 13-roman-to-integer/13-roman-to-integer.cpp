class Solution {
public:
    int romanToInt(string s) {
        int n=s.size();
        int ans=0;
        for(int i=0 ; i<n ; i++){
            if(s[i]=='M'){
                ans+=1000;
            }
            else if(s[i]=='D'){
                ans+=500;
            }
            else if(s[i]=='C'){
                if(i<n-1 && (s[i+1]=='D' || s[i+1]=='M')){
                    ans-=100;
                }
                else ans+=100;
            }
            else if(s[i]=='L'){
                ans+=50;
            }
            else if(s[i]=='X'){
                if(i<n-1 && (s[i+1]=='L' || s[i+1]=='C')){
                    ans-=10;
                }
                else ans+=10;
            }
            else if(s[i]=='V'){
                ans+=5;
            }
            else{
                if(i<n-1 && (s[i+1]=='V' || s[i+1]=='X')){
                    ans-=1;
                }
                else ans+=1;
            }
            // cout<<ans<<" ";
        }
        return ans;
    }
};