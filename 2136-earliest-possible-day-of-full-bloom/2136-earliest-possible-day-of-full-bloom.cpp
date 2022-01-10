class Solution {
public:
    int earliestFullBloom(vector<int>& p, vector<int>& g) {
        vector<pair<int,int>> v;
        for(int i=0 ; i<p.size() ; i++){
            v.push_back({-g[i],p[i]});
        }
        int cur=0,mx=0;
        sort(v.begin(),v.end());
        for(auto& i:v){
            mx=max(mx,cur+i.second-i.first);
            cur+=i.second;
        }
        return mx;
    }
};