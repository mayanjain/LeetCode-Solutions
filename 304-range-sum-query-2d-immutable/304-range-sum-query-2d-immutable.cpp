class NumMatrix {
public:
    vector<vector<int>> mat;
    
    NumMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        mat.resize(n);
        for(int i=0 ; i<n ; i++){
            mat[i].resize(m+1);
            for(int j=0 ; j<m ; j++){
                mat[i][j+1]=mat[i][j]+matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans=0;
        for(int i=row1 ; i<=row2 ; i++){
            ans+=mat[i][col2+1]-mat[i][col1];
        }
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */