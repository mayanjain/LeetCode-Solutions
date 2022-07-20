class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> v(26);
        for(int i=0 ; i<s.size() ; i++){
            v[s[i]-'a'].push_back(i);
        }
        int ans=0;
        for(auto& w:words){
            int j=-1;
            for(int i=0 ; i<w.size() ; i++){
                auto x=upper_bound(v[w[i]-'a'].begin(),v[w[i]-'a'].end(),j);
                if(x==v[w[i]-'a'].end()){
                    j=-1;
                    break;
                }
                j=*x;
            }
            if(j>=0)ans++;
        }
        return ans;
    }
};