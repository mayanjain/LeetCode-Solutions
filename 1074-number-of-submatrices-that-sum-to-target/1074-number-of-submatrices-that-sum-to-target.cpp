class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        if(target>1e7 || target<-1e7)return 0;
        int m=matrix.size(),n=matrix[0].size(),ans=0;
        for(int i=0 ; i<m ; i++){
            for(int j=1 ; j<n ; j++){
                matrix[i][j]+=matrix[i][j-1];
            }
        }
        unordered_map<int,int> mp;
        for(int i=0 ; i<n ; i++){
            for(int j=i ; j<n ; j++){
                mp.clear();
                mp[0]++;
                int cur=0;
                for(int k=0 ; k<m ; k++){
                    cur+=matrix[k][j]-(i?matrix[k][i-1]:0);
                    if(mp.count(cur-target))ans+=mp[cur-target];
                    mp[cur]++;
                }
            }
        }
        return ans;
    }
};