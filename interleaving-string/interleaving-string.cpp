class Solution {
public:    
    bool can(string s1, string s2, string s3,int i,int j,int k,vector<vector<int>>& v) {
        if(i==s1.size())return s2.substr(j)==s3.substr(k);
        if(j==s2.size())return s1.substr(i)==s3.substr(k);
        if(v[i][j]!=-1)return v[i][j];
        bool ans=false;
        if(s1[i]==s3[k]){
            ans|=can(s1,s2,s3,i+1,j,k+1,v);
        }
        if(s2[j]==s3[k]){
            ans|=can(s1,s2,s3,i,j+1,k+1,v);
        }
        return v[i][j]=ans;
    }
    
    bool isInterleave(string s1,string s2,string s3){
        if(s1.size()+s2.size()!=s3.size())return false;
        vector<vector<int>> v(s1.size(),vector<int>(s2.size(),-1));
        return can(s1,s2,s3,0,0,0,v);
    }
};