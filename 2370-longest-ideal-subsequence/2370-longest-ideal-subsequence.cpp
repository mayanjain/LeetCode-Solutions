class Solution {
public:
    int longestIdealString(string s, int k) {
        map<char,int> mp;
        int ans=0;
        for(int i=0 ; i<s.size() ; i++){
            mp[s[i]]++;
            for(char j='a' ; j<='z' ; j++){
                if(abs(s[i]-j)<=k && s[i]!=j)mp[s[i]]=max(mp[s[i]],mp[j]+1);
            }
            ans=max(ans,mp[s[i]]);
        }
        return ans;
    }
};