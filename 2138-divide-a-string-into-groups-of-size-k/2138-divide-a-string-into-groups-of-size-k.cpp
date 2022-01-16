class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        int c=0;
        string st="";
        for(auto& i:s){
            c++;
            st+=i;
            if(c==k){
                ans.push_back(st);
                st="";
                c=0;
            }
        }
        if(st!=""){
            while(c!=k){
                c++;
                st+=fill;
            }
            ans.push_back(st);
        }
        return ans;
    }
};