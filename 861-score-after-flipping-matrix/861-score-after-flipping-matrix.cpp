class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0 ; i<m ; i++){
            if(grid[i][0]!=1){
                for(int j=0 ; j<n ; j++){
                    if(grid[i][j])grid[i][j]=0;
                    else grid[i][j]=1;
                }
            }
        }
        for(int i=0 ; i<n ; i++){
            int z=0,o=0;
            for(int j=0 ; j<m ; j++){
                if(grid[j][i])o++;
                else z++;
            }
            if(z>o){
                for(int j=0 ; j<m ; j++){
                    if(grid[j][i])grid[j][i]=0;
                    else grid[j][i]=1;
                }
            }
        }
        int sum=0;
        for(int i=0 ; i<m ; i++){
            int k=0;
            for(int j=n-1 ; j>=0 ; j--,k++){
                if(grid[i][j])sum+=(1LL<<k);
            }
        }
        return sum;
    }
};