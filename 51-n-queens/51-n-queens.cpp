class Solution {
public:
    vector<vector<string>> ans;
    
    bool safe(int row,int col,vector<string>& v,int n){
        for(int i=0 ; i<row ; i++){
            if(v[i][col]=='Q')return false;
        }
        int i=row-1,j=col-1;
        while(i>=0 && j>=0){
            if(v[i--][j--]=='Q')return false;
        }
        i=row-1,j=col+1;
        while(i>=0 && j<n){
            if(v[i--][j++]=='Q')return false;
        }
        return true;
    }
    
    void solve(int row,int n,vector<string>& v){
        if(row==n){
            ans.push_back(v);
            return ;
        }
        for(int i=0 ; i<n ; i++){
            if(safe(row,i,v,n)){
                v[row][i]='Q';
                solve(row+1,n,v);
                v[row][i]='.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> v(n);
        for(auto& i:v)i=string(n,'.');
        solve(0,n,v);
        return ans;
    }
};