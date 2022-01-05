class Solution {
public:
    vector<vector<string>> ans;
    
    bool pal(string& s){
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j])return 0;
            i++;j--;
        }
        return 1;
    }
    
    void solve(string s,int st,vector<string>& v){
        if(st==s.size()){
            ans.push_back(v);
            return;
        }
        string k="";
        for(int i=st ; i<s.size() ; i++){
            k+=s[i];
            if(pal(k)){
                v.push_back(k);
                solve(s,i+1,v);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> v;
        solve(s,0,v);
        return ans;
    }
};