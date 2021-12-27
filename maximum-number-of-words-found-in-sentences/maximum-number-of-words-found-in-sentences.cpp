class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int ans=0;
        for(auto& i:sentences){
            int c=1;
            for(auto& j:i){
                if(j==' ')c++;
            }
            ans=max(ans,c);
        }
        return ans;
    }
};