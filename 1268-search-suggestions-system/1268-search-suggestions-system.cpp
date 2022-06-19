class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& p, string s) {
        int n=s.size();
        vector<vector<string>> ans(n);
        string cur="";
        // set<string> p;
        priority_queue<string> pq;
        // for(auto& i:products)p.insert(i);
        for(int i=0 ; i<n ; i++){
            cur+=s[i];
            for(auto& j:p){
                if(j.substr(0,i+1)==cur){
                    pq.push(j);
                    if(pq.size()>3)pq.pop();
                }
            }
            while(pq.size()){
                ans[i].push_back(pq.top());
                pq.pop();
            }
            reverse(ans[i].begin(),ans[i].end());
        }
        return ans;
    }
};