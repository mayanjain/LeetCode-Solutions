class Solution {
public:
    int find(vector<int>& v,int c){
        if(v[c]==c)return c;
        return v[c]=find(v,v[c]);
    }
    
    bool equationsPossible(vector<string>& equations) {
        vector<int> v(26);
        for(int i=0 ; i<26 ; i++)v[i]=i;
        for(auto& eq:equations){
            if(eq[1]=='='){
                v[find(v,eq[0]-'a')]=find(v,eq[3]-'a');
            }
        }
        for(auto& eq:equations){
            if(eq[1]=='!'){
                if(find(v,eq[0]-'a')==find(v,eq[3]-'a'))return false;
            }
        }
        return true;
    }
};