class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& p) {
        sort(p.begin(),p.end());
        int n=p.size(),ans=0,def=p[n-1][1];
        vector<int> mx(n);
        for(int i=n-2 ; i>=0 ; i--){
            if(p[i][0]!=p[i+1][0])mx[i]=def;
            else mx[i]=mx[i+1];
            def=max(def,p[i][1]);
        }
        for(int i=0 ; i<n ; i++){
            if(mx[i]>p[i][1])ans++;
        }
        return ans;
    }
};