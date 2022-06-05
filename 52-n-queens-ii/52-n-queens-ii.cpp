class Solution {
public:
    int ans=0;
    
    bool safe(int row,int col,vector<vector<bool>>& v){
        for(int i=row-1 ; i>=0 ; i--){
            if(v[i][col])return false;
        }
        int i=row,j=col;
        while(i>=0 && j>=0){
            if(v[i--][j--])return false;
        }
        i=row,j=col;
        while(i>=0 && j<v.size()){
            if(v[i--][j++])return false;
        }
        return true;
    }
    
    void check(vector<vector<bool>>& b,int row,int n){
        if(row==n){
            ans++;
            return;
        }
        for(int i=0 ; i<n ; i++){
            if(safe(row,i,b)){
                b[row][i]=1;
                check(b,row+1,n);
                b[row][i]=0;
            }
        }
    }
    
    int totalNQueens(int n) {
        vector<vector<bool>> v(n,vector<bool>(n,0));
        check(v,0,n);
        return ans;
    }
};