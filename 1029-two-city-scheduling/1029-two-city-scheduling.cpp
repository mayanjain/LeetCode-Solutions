class Solution {
public:
    static bool cmp(vector<int>& v,vector<int>& z){
        return v[1]-v[0]>z[1]-z[0];
    }
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(),costs.end(),cmp);
        int ans=0;
        for(int i=0 ; i<costs.size()/2 ; i++)ans+=costs[i][0];
        for(int i=costs.size()/2 ; i<costs.size() ; i++)ans+=costs[i][1];
        return ans;
    }
};