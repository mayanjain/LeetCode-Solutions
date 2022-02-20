class Solution {
public:
    static bool cmp(vector<int>& v,vector<int>& z){
        if(v[0]!=z[0])return v[0]<z[0];
        return v[1]>z[1];
    }
    
    int removeCoveredIntervals(vector<vector<int>>& it) {
        sort(it.begin(),it.end(),cmp);
        auto cur=it[0];
        int n=it.size();
        int mx=0;
        for(int i=0 ; i<it.size() ; i++){
            if(mx>=it[i][1])n--;
            mx=max(mx,it[i][1]);
            // cout<<it[i][0]<<" "<<it[i][1]<<"  ";
        }
        return n;
    }
};