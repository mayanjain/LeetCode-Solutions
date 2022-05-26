class TrieNode{
    public:
    bool is_word=false;
    vector<TrieNode*> next;
    
    TrieNode(){
        next.resize(26);
    }
};

class Trie {
public:
    TrieNode* root;
    
    Trie() {  
        root=new TrieNode();
    }
    
    void insert(string word) {
        auto cur=root;
        for(auto& i:word){
            int id=i-'a';
            if(cur->next[id]==NULL){
                cur->next[id]=new TrieNode();
            }
            cur=cur->next[id];
        }
        cur->is_word=true;
    }
    
    bool search(string word) {
        auto cur=root;
        for(auto& i:word){
            int id=i-'a';
            if(cur->next[id]==NULL)return false;
            cur=cur->next[id];
        }
        return cur->is_word==true;
    }
    
    bool startsWith(string word) {
        auto cur=root;
        for(auto& i:word){
            int id=i-'a';
            if(cur->next[id]==NULL)return false;
            cur=cur->next[id];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */