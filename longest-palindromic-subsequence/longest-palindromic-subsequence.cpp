class Solution {
public:
    
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> v(s.size(),vector<int>(s.size()));
        for(int i=0 ; i<s.size() ; i++){
            v[i][i]=1;
            for(int j=i-1; j>=0 ; j--){
                if(s[j]==s[i])v[j][i]=v[j+1][i-1]+2;
                else v[j][i]=max(v[j+1][i],v[j][i-1]);
            }
        }
        return v[0][s.size()-1];
    }
};