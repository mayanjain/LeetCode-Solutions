class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        map<int,vector<int>> mp;
        for(int i=0 ; i<mat.size() ; i++){
            for(int j=0 ; j<mat[i].size() ; j++){
                mp[j-i].push_back(mat[i][j]);
            }
        }
        for(auto& i:mp){
            sort(i.second.begin(),i.second.end(),greater<int>());
        }
        for(int i=0 ; i<mat.size() ; i++){
            for(int j=0 ; j<mat[i].size() ; j++){
                mat[i][j]=mp[j-i].back();
                mp[j-i].pop_back();
            }
        }
        return mat;
    }
};