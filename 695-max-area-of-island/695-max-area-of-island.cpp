class Solution {
public:
    
    void dfs(vector<vector<int>>& grid,int i,int j,int& area){
        int n=grid.size(),m=grid[0].size();
        if(i==n || j==m || i==-1 || j==-1 || grid[i][j]==0)return;
        area++;
        grid[i][j]=0;
        dfs(grid,i-1,j,area);
        dfs(grid,i+1,j,area);
        dfs(grid,i,j-1,area);
        dfs(grid,i,j+1,area);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size(),ans=0;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(grid[i][j]){
                    int area=0;
                    dfs(grid,i,j,area);
                    ans=max(area,ans);
                }
            }
        }
        return ans;
    }
};