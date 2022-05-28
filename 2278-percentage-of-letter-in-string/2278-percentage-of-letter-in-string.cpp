class Solution {
public:
    int percentageLetter(string s, char letter) {
        int count=0;
        for(int i=0 ; i<s.size() ; i++){
            count+=(s[i]==letter);
        }
        return count*100/s.size();
    }
};