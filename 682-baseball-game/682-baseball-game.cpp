class Solution {
public:
    int calPoints(vector<string>& ops) {
        long sum=0;
        vector<long> v;
        for(int i=0 ; i<ops.size() ; i++){
            if(ops[i]=="C"){
                v.pop_back();
            }
            else if(ops[i]=="D"){
                v.push_back(v.back()*2);
            }
            else if(ops[i]=="+"){
                v.push_back(v[v.size()-1]+v[v.size()-2]);
            }
            else{
                v.push_back(stoll(ops[i]));
            }
        }
        for(auto& i:v)sum+=i;
        return sum;
    }
};