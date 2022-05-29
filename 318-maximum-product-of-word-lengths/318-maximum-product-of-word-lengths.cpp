class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n=words.size();
        vector<set<char>> v(n);
        int ans=0;
        for(int i=0 ; i<n ; i++){
            for(auto& j:words[i])v[i].insert(j);
            for(int j=0 ; j<i ; j++){
                bool ok=1;
                for(auto& k:words[j]){
                    if(v[i].count(k)){
                        ok=0;
                        break;
                    }
                }
                if(ok)ans=max(ans,int(words[i].size()*words[j].size()));
            }
        }
        return ans;
    }
};