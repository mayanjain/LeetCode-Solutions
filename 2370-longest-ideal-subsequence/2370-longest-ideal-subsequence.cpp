class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int> mp(26);
        int ans=0;
        for(int i=0 ; i<s.size() ; i++){
            mp[s[i]-'a']++;
            for(char j='a' ; j<='z' ; j++){
                if(abs(s[i]-j)<=k && s[i]!=j)mp[s[i]-'a']=max(mp[s[i]-'a'],mp[j-'a']+1);
            }
            ans=max(ans,mp[s[i]-'a']);
        }
        return ans;
    }
};