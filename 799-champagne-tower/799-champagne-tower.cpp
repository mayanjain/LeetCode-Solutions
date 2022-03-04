class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> v(102,vector<double>(102));
        v[0][0]=poured;
        for(int r=0 ; r<=query_row ; ++r){
            for(int c=0; c<=r ; ++c){
                double q=(v[r][c]-1.0)/2.0;
                if(q>0){
                    v[r+1][c]+=q;
                    v[r+1][c+1]+=q;
                }
            }
        }
        return min(1.0,v[query_row][query_glass]);
    }
};