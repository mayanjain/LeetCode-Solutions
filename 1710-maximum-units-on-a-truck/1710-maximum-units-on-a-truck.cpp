class Solution {
public:
    int maximumUnits(vector<vector<int>>& box, int truck) {
        sort(box.begin(),box.end(),[](vector<int> v,vector<int> z){return v[1]>z[1];});
        int ans=0;
        for(int i=0 ; i<box.size() && truck ; i++){
            int cur=min(box[i][0],truck);
            ans+=cur*box[i][1];
            truck-=cur;
        }
        return ans;
    }
};