class Solution {
public:
    bool pred(string& a,string& b){
        if(a.size()!=b.size()+1)return 0;
        int c=0;
        for(int i=0,j=0 ; j<b.size() && c<=1 ; i++,j++){
            if(a[i]!=b[j]){
                j--;
                c++;
            }
        }
        return c<=1;
    }
    
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),[](string& a,string& b){return a.size()<b.size();});
        int n=words.size(),ans=0;
        vector<int> dp(n,1);
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<i ; j++){
                if(pred(words[i],words[j])){
                    dp[i]=max(dp[j]+1,dp[i]);
                }
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};