class Solution {
public:
    int triangularSum(vector<int>& v) {
        for(int i=0 ; i<v.size() ; i++){
            for(int j=0 ; j<v.size()-1-i ; j++){
                v[j]=(v[j]+v[j+1])%10;
            }
        }
        return v[0];
    }
};