class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string s=to_string(n);
        sort(s.begin(),s.end());
        do{
            if(s[0]=='0')continue;
            int x=stoi(s);
            while(x%2==0)x/=2;
            if(x==1)return true;
        }while(next_permutation(s.begin(),s.end()));
        return false;
    }
};