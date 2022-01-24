class Solution {
public:
    bool detectCapitalUse(string word) {
        int n=word.size(),cap=0;
        for(auto& i:word){
            if(i>='A' && i<='Z')cap++;
        }
        return (cap==n || (cap==1 && word[0]>='A' && word[0]<='Z') || cap==0);
    }
};