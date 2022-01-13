class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        for(int i=1 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                int cur=matrix[i-1][j];
                if(j>0)cur=min(matrix[i-1][j-1],cur);
                if(j<n-1)cur=min(cur,matrix[i-1][j+1]);
                matrix[i][j]+=cur;
            }
        }
        int ans=INT_MAX;
        for(int i=0 ; i<n ; i++){
            ans=min(ans,matrix[m-1][i]);
        }
        return ans;
    }
};