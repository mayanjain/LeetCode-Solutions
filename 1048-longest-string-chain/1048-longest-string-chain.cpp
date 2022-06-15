class Solution {
public:
    
    map<pair<int,string>,int> mp;
    
    int solve(vector<string>& words,int pos,string s){
        if(pos==words.size())return 0;
        if(s.size()==words[pos].size())return solve(words,pos+1,s);
        if(s.size()+1!=words[pos].size() && s!="")return 0;
        if(mp.count({pos,s}))return mp[{pos,s}];
        int c=0;
        for(int i=0,j=0 ; i<words[pos].size() && s!=""; i++,j++){
            if(words[pos][i]!=s[j]){
                j--;
                c++;
            }
        }
        // cout<<c<<" ";
        int res=0;
        if(c<=1){
            res=1+solve(words,pos+1,words[pos]);
        }
        res=max(res,solve(words,pos+1,s));
        return mp[{pos,s}]=res;
    }
    
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),[](string& w,string& x){return w.size()<x.size();});
        return solve(words,0,"");        
    }
};