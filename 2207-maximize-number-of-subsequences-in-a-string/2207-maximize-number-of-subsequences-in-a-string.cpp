class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        text+=pattern[1];
        long long cur=0,ans=0,a=0;
        for(int i=0 ; i<text.size() ; i++){
            if(text[i]==pattern[1])ans+=a;
            if(text[i]==pattern[0])a++;
        }
        text.pop_back();
        a=1;
        for(int i=0 ; i<text.size() ; i++){
            if(text[i]==pattern[1])cur+=a;
            if(text[i]==pattern[0])a++;
        }
        return max(ans,cur);
    }
};