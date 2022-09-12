class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int ans=0,n=tokens.size(),i=0,j=n-1,score=0;
        while(i<=j){
            if(tokens[i]<=power){
                power-=tokens[i++];
                ans=max(ans,++score);
            }
            else if(score){
                power+=tokens[j--];
                --score;
            }
            else break;
        }
        return ans;
    }
};