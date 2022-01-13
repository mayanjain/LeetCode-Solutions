class Solution {
public:
    static bool cmp(vector<int>& p,vector<int>& v){
        return p[1]<v[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),cmp);
        long cur=LONG_MIN,ans=0;
        for(int i=0 ; i<points.size() ; i++){
            if(points[i][0]<=cur && points[i][1]>=cur)continue;
            ans++;
            cur=points[i][1];
        }
        return ans;
    }
};