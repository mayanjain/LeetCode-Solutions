class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& sf) {
        vector<int> v(s.size()+1);
        for(auto& i:sf){
            if(i[2]==0){
                v[i[0]]--;
                v[i[1]+1]++;
            }
            else{
                v[i[0]]++;
                v[i[1]+1]--;
            }
        }
        for(int i=0 ; i<v.size() ; i++){
            if(i)v[i]+=v[i-1];
            int cur=((s[i]-'a'+v[i])%26+26)%26+'a';
            s[i]=char(cur);
        }
        return s;
    }
};