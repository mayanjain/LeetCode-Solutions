class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        int row=startPos[0],col=startPos[1];
        vector<int> ans(s.size());
        for(int i=0 ; i<s.size() ; i++){
            col=startPos[1],row=startPos[0];
            for(int j=i; j<s.size() ; j++){
                if(s[j]=='L')col--;
                if(s[j]=='R')col++;
                if(s[j]=='U')row--;
                if(s[j]=='D')row++;
                if(col<n && col>=0 && row>=0 && row<n)ans[i]++;
                else break;
            }
        }
        return ans;
    }
};