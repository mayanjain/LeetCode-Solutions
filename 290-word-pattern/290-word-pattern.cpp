class Solution {
public:
    bool wordPattern(string p, string s) {
        unordered_map<char,string> mp;
        unordered_map<string,char> up;
        stringstream ss(s);
        string word;
        int i=0;
        while(ss>>word){
            if(i==p.size())return 0;
            if(mp.count(p[i]) && mp[p[i]]!=word)return false;
            if(up.count(word) && up[word]!=p[i])return false;
            up[word]=p[i];
            mp[p[i++]]=word;
            // cout<<word;
        }
        return i==p.size();
    }
};