class Solution {
public:
    bool canConstruct(string s, int k) {
        if(k>s.size())return false;
        map<char,int> mp;
        for(auto& i:s)mp[i]++;
        int single=0;
        for(char i='a' ; i<='z' ; i++){
            single+=mp[i]%2;
        }
        if(single<=k)return true;
        return false;
    }
};