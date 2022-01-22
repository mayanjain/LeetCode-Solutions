class Solution {
public:
    unordered_map<int,bool> mp;
    bool winnerSquareGame(int n) {
        if(mp.count(n))return mp[n];
        for(int i=1 ; i<=sqrt(n) ; i++){
            if(!winnerSquareGame(n-i*i)){
                mp[n]=true;
                return true;
            }
        }
        return mp[n]=false;
    }
};