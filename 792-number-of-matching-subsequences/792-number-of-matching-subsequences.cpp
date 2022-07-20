class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> v(s.size()+1,vector<int>(26,-1));
        for(int i=s.size()-1 ; i>=0 ; i--){
            v[i]=v[i+1];
            v[i][s[i]-'a']=i;
        }
        int ans=0;
        for(auto& w:words){
            int j=0;
            for(int i=0 ; i<w.size() && j!=-1 ; i++){
                int x=v[j][w[i]-'a'];
                j=x+1;
                if(x==-1)break;
            }
            if(j)ans++;
        }
        return ans;
    }
};