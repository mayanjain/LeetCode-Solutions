class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int ans=k,cur=0;
        for(int i=0 ; i<blocks.size() ; i++){
            cur+=blocks[i]=='W';
            cur-=((i>=k)&&(blocks[i-k]=='W'));
            if(i>=k-1)ans=min(ans,cur);
        }
        return ans;
    }
};