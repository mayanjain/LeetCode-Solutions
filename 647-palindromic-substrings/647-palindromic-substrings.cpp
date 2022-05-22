class Solution {
public:
    int check(string& s,int st,int end){
        int ans=0;
        while(st>=0 && end<s.size()){
            if(s[st]!=s[end])break;
            ans++;
            st--;end++;
        }
        return ans;
    }
    
    int countSubstrings(string s) {
        int ans=0;
        for(int i=0 ; i<s.size() ; i++){
            ans+=check(s,i,i)+check(s,i,i+1);
        }
        return ans;
    }
};