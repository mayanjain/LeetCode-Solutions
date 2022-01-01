class Solution {
public:
    void solve(vector<int>& v,int p,int& ans){
        if(p==v.size()){
            ans++;
        }
        for(int i=p ; i<v.size() ; i++){
            swap(v[i],v[p]);
            if(v[p]%p==0 || p%v[p]==0)solve(v,p+1,ans);
            swap(v[i],v[p]);
        }
    }
    
    int countArrangement(int n) {
        vector<int> v(n+1);
        for(int i=1; i<=n ; i++)v[i]=i;
        int ans=0;
        solve(v,1,ans);
        return ans;
    }
};