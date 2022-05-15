class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans=0,n=grid.size(),m=grid[0].size();
        vector<vector<int>> v(n+2,vector<int>(m+2));
        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; j<=m ; j++){
                v[i][j]=grid[i-1][j-1];
            }
        }
        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; j<=m ; j++){
                if(v[i][j]){
                    if(!v[i-1][j])ans++;
                    if(!v[i][j-1])ans++;
                    if(!v[i+1][j])ans++;
                    if(!v[i][j+1])ans++;
                }
            }
        }
        return ans;
    }
};