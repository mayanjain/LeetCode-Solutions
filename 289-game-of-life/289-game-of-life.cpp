class Solution {
public:
    
    int neighbors(vector<vector<int>>& board,int row,int column){
        int m=board.size(),n=board[0].size();
        int count=0;
        if(row>0){
            for(int i=max(column-1,0) ; i<=min(n-1,column+1) ; i++){
                if(board[row-1][i])count++;
            }
        }
        if(row<m-1){
            for(int i=max(column-1,0) ; i<=min(n-1,column+1) ; i++){
                if(board[row+1][i])count++;
            }
        }
        if(column>0)count+=board[row][column-1];
        if(column<n-1)count+=board[row][column+1];
        
        return count;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size(),n=board[0].size();
        vector<vector<int>> ans(m,vector<int>(n));
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                int count=neighbors(board,i,j);
                if(board[i][j]){
                    if(count>1 && count<4)ans[i][j]=1;
                }
                else{
                    if(count==3)ans[i][j]=1;
                }
            }
        }
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                board[i][j]=ans[i][j];
            }
        }
    }
};