class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int,int> mp;
        int ans=0;
        for(auto& i:time){
            int cur=i%60;
            if(mp.find(60-cur)!=mp.end()){
                ans+=mp[60-cur];
            }
            else if(cur==0){
                ans+=mp[cur];
            }
            mp[cur]++;
            cout<<cur<<" ";
        }
        return ans;
    }
};