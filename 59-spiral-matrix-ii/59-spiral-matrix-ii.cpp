class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> v(n,vector<int>(n));
        int cur=0,k=1,rowStart=0,rowEnd=n-1,colStart=0,colEnd=n-1;
        while(colStart<=colEnd || rowStart<=rowEnd){
            for(int i=colStart ; i<=colEnd ; i++){
                v[rowStart][i]=k++;
            }
            rowStart++;
            for(int i=rowStart ; i<=rowEnd ; i++){
                v[i][colEnd]=k++;
            }
            colEnd--;
            for(int i=colEnd ; i>=colStart ; i--){
                v[rowEnd][i]=k++;
            }
            rowEnd--;
            for(int i=rowEnd ; i>=rowStart ; i--){
                v[i][colStart]=k++;
            }
            colStart++;
        }
        return v;
    }
};