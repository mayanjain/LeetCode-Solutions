class Solution {
public:
    string convert(string s, int numRows) {
        vector<vector<char>> v(numRows,vector<char>(1000,'-'));
        int i=0,n=s.size(),c=0;
        while(i<n){
            for(int j=0 ; j<numRows && i<s.size() ; j++){
                v[j][c]=s[i++];
            }
            c++;
            for(int k=numRows-2 ; k>0 && i<s.size() ; k--){
                v[k][c++]=s[i++];
            }
            c++;
        }
        string ans="";
        for(auto& i:v)for(auto& j:i){
            if(j!='-')ans+=j;
        }
        return ans;
    }
};