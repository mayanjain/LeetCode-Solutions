class WordFilter {
public:
    map<string,int> mp;
    
    WordFilter(vector<string>& words) {
        for(int i=0 ; i<words.size() ; i++){
            string pref="",suf="";
            for(int l=0 ; l<words[i].size() ; l++){
                pref+=words[i][l];
                for(int r=words[i].size()-1 ; r>=0 ; r--){
                    suf+=words[i][r];
                    mp[pref+" "+suf]=i;
                }
                suf="";
            }
        }
    }
    
    int f(string pref, string suf) {
        reverse(suf.begin(),suf.end());
        if(!mp.count(pref+" "+suf))return -1;
        return mp[pref+" "+suf];
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */