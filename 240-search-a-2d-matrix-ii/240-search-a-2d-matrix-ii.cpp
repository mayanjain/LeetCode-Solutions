class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(),n=matrix[0].size(),low=0,high=m*n-1;
        for(auto& row:matrix)for(auto& col:row){
            if(col==target)return true;
        }
        return false;
    }
};