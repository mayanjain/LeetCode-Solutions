class Solution {
public:
    map<pair<int,char>,int> mp;
    
    int solve(int n,char c,int i){
        if(i==n+1)return 1;
        if(mp.count({i,c}))return mp[{i,c}];
        int ans=0;
        for(char j=c ; j<='e' ; j++){
            ans+=solve(n,j,i+1);
        }
        return mp[{i,c}]=ans;
    }
    
    int countVowelStrings(int n) {
        return solve(n,'a',1);
    }
};