class WordDictionary {
    private:
        unordered_map<int,vector<string>> mp;
        bool isEqual(string &s,string& t){
            for(int i=0 ; i<s.size() ; i++){
                if(t[i]=='.')continue;
                if(t[i]!=s[i])return false;
            }
            return true;
        }
    
    public:
        WordDictionary() {
        }

        void addWord(string word) {
            mp[word.size()].push_back(word);
        }

        bool search(string word) {
            for(auto& i:mp[word.size()])if(isEqual(i,word))return true;
            return false;
        }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */