class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string,int> mp,up;
        for(auto& i:words1)mp[i]++;
        for(auto& i:words2)up[i]++;
        int ans=0;
        for(auto& i:mp)if(i.second==1 && up[i.first]==1)ans++;
        return ans;
    }
};