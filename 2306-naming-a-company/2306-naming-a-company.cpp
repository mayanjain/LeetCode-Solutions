class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        long long ans=0;
        vector<unordered_set<string>> mp(26);
        for(auto& i:ideas){
            mp[i[0]-'a'].insert(i.substr(1));
        }
        for(int i=0 ; i<=25 ; i++){
            for(int j=i+1 ; j<=25 ; j++){
                long c1=0,c2=0;
                for(auto& k:mp[i]){
                    if(!mp[j].count(k))c1++;
                }
                for(auto& k:mp[j]){
                    if(!mp[i].count(k))c2++;
                }
                ans+=c1*c2;
            }
        }
        return ans*2;
    }
};