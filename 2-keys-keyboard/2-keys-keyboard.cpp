class Solution {
public:
    int minSteps(int n) {
        vector<int> v(n+1);
        for(int i=2; i<=n ; i++){
            v[i]=i;
            for(int j=i-1 ; j>1 ; j--){
                if(i%j==0){
                    v[i]=v[j]+i/j;
                    break;
                }
            }
        }
        return v[n];
    }
};