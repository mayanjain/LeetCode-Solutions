class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for(auto& s:words){
            map<char,char> mp,up;
            bool ok=1;
            for(int i=0 ; i<s.size() ; i++){
                if(!mp.count(s[i]))mp[s[i]]=pattern[i];
                if(!up.count(pattern[i]))up[pattern[i]]=s[i];
                if(mp[s[i]]!=pattern[i] || up[pattern[i]]!=s[i])ok=0;
            }
            if(ok)ans.push_back(s);
        }
        return ans;
    }
};