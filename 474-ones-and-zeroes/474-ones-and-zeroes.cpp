class Solution {
public:
    int mp[601][101][101];
    int findMaxForm(vector<string>& strs, int m, int n,int c=0) {
        if(c==strs.size() || (m==0 && n==0))return 0;
        if(mp[c][m][n]){
            return mp[c][m][n];
        }
        int one=0,zero;
        for(auto& i:strs[c])if(i=='1')one++;
        zero=strs[c].size()-one;
        int ans=0;
        if(one<=n && zero<=m){
            ans=1+findMaxForm(strs,m-zero,n-one,c+1);
        }
        ans=max(ans,findMaxForm(strs,m,n,c+1));
        return mp[c][m][n]=ans;
    }
};