class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string s) {
        int n=s.size();
        vector<vector<string>> ans(n);
        string cur="";
        unordered_set<string> p,er;
        priority_queue<string> pq;
        for(auto& i:products)p.insert(i);
        for(int i=0 ; i<n ; i++){
            cur+=s[i];
            for(auto& j:p){
                if(j.substr(0,i+1)==cur){
                    pq.push(j);
                    if(pq.size()>3)pq.pop();
                }
                else{
                    er.insert(j);
                }
            }
            for(auto& i:er){
                p.erase(i);
            }
            er.clear();
            while(pq.size()){
                ans[i].push_back(pq.top());
                pq.pop();
            }
            reverse(ans[i].begin(),ans[i].end());
        }
        return ans;
    }
};