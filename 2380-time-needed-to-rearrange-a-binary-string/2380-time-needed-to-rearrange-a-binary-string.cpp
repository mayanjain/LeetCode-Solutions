class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int ans=0,zero=0;
        for(auto& i:s){
            if(i=='0')zero++;
            else if(zero)ans=max(ans+1,zero);
        }
        return ans;
    }
};