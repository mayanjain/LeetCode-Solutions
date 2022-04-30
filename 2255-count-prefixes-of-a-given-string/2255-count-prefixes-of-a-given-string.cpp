class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int ans=0;
        for(auto& i:words){
            bool k=1;
            if(i.size()>s.size())continue;
            for(int j=0 ; j<i.size() && j<s.size() ; j++){
                if(s[j]!=i[j]){
                    k=0;
                    break;
                }
            }
            ans+=k;
        }
        return ans;
    }
};