class Solution {
public:
    bool wordPattern(string p, string s) {
        unordered_map<char,int> mp;
        unordered_map<string,int> up;
        stringstream ss(s);
        string word;
        int i=0;
        while(ss>>word){
            if(i==p.size() || mp[p[i]]!=up[word])return 0;
            mp[p[i]]=i+1;up[word]=i+1;i++;
        }
        return i==p.size();
    }
};