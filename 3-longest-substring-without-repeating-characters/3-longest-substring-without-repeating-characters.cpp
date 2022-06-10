class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> bits(256);
        int st=0,ans=0;
        for(int i=0 ; i<s.size() ; i++){
            bits[s[i]]++;
            while(bits[s[i]]>1){
                bits[s[st++]]--;
            }
            ans=max(ans,i-st+1);
        }
        return ans;
    }
};