class Solution {
public:
    int minDeletions(string s) {
        vector<int> mp(26);
        for(auto& i:s)mp[i-'a']++;
        sort(mp.begin(),mp.end(),greater<int>());
        int ans=0;
        for(int i=1 ; i<26 ; i++){
            if(mp[i-1]<=mp[i]){
                int ls=mp[i];
                mp[i]=max(0,mp[i-1]-1);
                ans+=ls-mp[i];
            }
        }
        return ans;
    }
};