class Solution {
public:
    map<pair<int,int>,int> mp;
    
    int solve(vector<vector<int>>& mat,int i,int j,int last){
        int n=mat.size(),m=mat[0].size();
        if(i==n || j==m || i==-1 || j==-1 || mat[i][j]<=last)return 0;
        if(mp.count({i,j}))return mp[{i,j}];
        int cur=0;
        cur=solve(mat,i+1,j,mat[i][j]);
        cur=max(cur,solve(mat,i,j+1,mat[i][j]));
        cur=max(cur,solve(mat,i-1,j,mat[i][j]));
        cur=max(cur,solve(mat,i,j-1,mat[i][j]));
        return mp[{i,j}]=cur+1;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        int ans=0;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                ans=max(solve(matrix,i,j,-1),ans);
            }
        }
        return ans;
    }
};