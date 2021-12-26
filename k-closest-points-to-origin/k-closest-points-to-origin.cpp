class Solution {
public:
    static bool cmp(vector<int>& v,vector<int>&z){
        return v[0]*v[0]+v[1]*v[1]<z[0]*z[0]+z[1]*z[1];
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(),points.end(),cmp);
        points.resize(k);
        return points;
    }
};