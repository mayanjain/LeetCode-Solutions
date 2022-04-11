class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size();
        k%=(m*n);
        vector<vector<int>> ans(m,vector<int>(n));
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                int new_y=(j+k)%n;
                int new_x=(i+(j+k)/n)%m;
                ans[new_x][new_y]=grid[i][j];
            }
        }
        return ans;
    }
};