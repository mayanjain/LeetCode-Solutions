class Solution {
public:
    
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<pair<int,int>> v;
        for(auto& i:trips){
            v.push_back({i[1],i[0]});
            v.push_back({i[2],-i[0]});
        }
        sort(v.begin(),v.end());
        int cur=0;
        for(auto& i:v){
            cur+=i.second;
            if(cur>capacity)return 0;
        }
        return true;
    }
};