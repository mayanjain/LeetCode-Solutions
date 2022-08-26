class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<string> v;
        string k=to_string(n);
        sort(k.begin(),k.end());
        for(int i=1 ; i<=1e9 ; i*=2){
            string s=to_string(i);
            sort(s.begin(),s.end());
            if(k==s)return true;
        }
        return false;
    }
};