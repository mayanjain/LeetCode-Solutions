class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        string k=s;
        sort(k.begin(),k.end(),greater<char>());
        int ans=0;
        while(s!=k){
            ans++;
            string z=s;
            for(int i=0 ; i+1<s.size() ; i++){
                if(s[i]=='0' && s[i+1]=='1'){
                    z[i]='1',z[i+1]='0';
                }
            }
            s=z;
        }
        return ans;
    }
};