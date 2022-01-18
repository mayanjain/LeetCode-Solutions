class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        int ls=0;
        for(int i=0 ; i<f.size() ; i++){
            if(f[i]){
                if(ls)n++;
                ls=1;
            }
            else{
                if(!ls){
                    n--;
                    ls=1;
                }
                else ls=0;
            }
        }
        return n<=0;
    }
};