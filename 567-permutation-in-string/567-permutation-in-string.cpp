class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size())return 0;
        vector<int> v(26);
        for(auto& i:s1)v[i-'a']++;
        int n=s1.size();
        for(int i=0 ; i<s2.size() ; i++){
            if(i>=n)v[s2[i-n]-'a']++;
            v[s2[i]-'a']--;
            int c=0;
            for(auto& i:v){
                if(i)c++;
            }
            if(!c)return 1;
        }
        return 0;
    }
};