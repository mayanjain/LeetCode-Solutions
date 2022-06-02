class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& mt) {
        int m=mt.size(),n=mt[0].size();
        vector<vector<int>> v(n,vector<int>(m));
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                v[j][i]=mt[i][j];
            }
        }
        return v;
    }
};