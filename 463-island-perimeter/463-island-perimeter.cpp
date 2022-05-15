class Solution {
public:
    int islandPerimeter(vector<vector<int>>& v) {
        int ans=0,n=v.size(),m=v[0].size();
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(v[i][j]){
                    if(i==0 || !v[i-1][j])ans++;
                    if(j==0 || !v[i][j-1])ans++;
                    if(i==n-1 || !v[i+1][j])ans++;
                    if(j==m-1 || !v[i][j+1])ans++;
                }
            }
        }
        return ans;
    }
};