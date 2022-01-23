class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for(long i=1 ; i<=9 ; i++){
            long a=0;
            for(long j=i ; j<=9 ; j++){
                a=a*10+j;
                if(a>=low && a<=high)ans.push_back(a);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};