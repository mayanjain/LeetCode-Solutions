class Solution {
public:
    
    static bool cmp(vector<int>& e1,vector<int>& e2){
        return e1[0]!=e2[0]?e1[0]<e2[0]:e1[1]>e2[1];
    }
    
    int maxEnvelopes(vector<vector<int>>& ev) {
        sort(ev.begin(),ev.end(),cmp);
        vector<int> lis;
        for(int i=0 ; i<ev.size() ; i++){
            auto it=lower_bound(lis.begin(),lis.end(),ev[i][1]);
            if(it==lis.end())lis.push_back(ev[i][1]);
            else *it=ev[i][1];
        }
        return lis.size();
    }
};