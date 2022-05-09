class Solution {
public:
    vector<string> ans;
    
    const vector<string> pad = {
        "", "", "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"
    };
    
    void solve(string& digits,int cur,string& s){
        if(cur==digits.size()){
            ans.push_back(s);
            return;
        }
        int k=digits[cur]-'0';
        for(auto& i:pad[k]){
            s.push_back(i);
            solve(digits,cur+1,s);
            s.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)return ans;
        string s="";
        solve(digits,0,s);
        return ans;
    }
};