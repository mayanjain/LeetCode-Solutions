class Encrypter {
public:
    map<string,int> count;
    vector<char> key;
    vector<string> vals;
    
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dict) {
        key=keys;
        vals=values;
        for(auto& d:dict){
            count[encrypt(d)]++;
        }
    }
    
    string encrypt(string word1) {
        string dec="";
        for(auto& i:word1){
            for(int j=0 ; j<key.size() ; j++){
                if(key[j]==i){
                    dec+=vals[j];
                    break;
                }
            }
        }
        return dec;
    }
    
    int decrypt(string word2) {
        return count[word2];
    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */