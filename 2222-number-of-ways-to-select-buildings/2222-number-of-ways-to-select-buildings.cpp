class Solution {
public:
    long long numberOfWays(string s) {
        long long zeros=0,ones=0;
        for(auto& i:s){
            if(i=='0')zeros++;
            else ones++;
        }
        long long curz=0,curo=0;
        long long ans=0;
        for(int i=0 ; i<s.size() ; i++){
            if(s[i]=='0'){
                ans+=curo*ones;
                curz++;zeros--;
            }
            else{
                ans+=zeros*curz;
                curo++;ones--;
            }
        }
        return ans;
    }
};