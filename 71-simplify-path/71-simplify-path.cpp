class Solution {
public:
    string simplifyPath(string path) {
        string cur="",ans="";
        path+='/';
        vector<string> v;
        for(auto& i:path){
            if(i=='/'){
                if(cur=="" || cur=="."){}
                else if(cur==".."){if(v.size())v.pop_back();}
                else v.push_back(cur);
                cur="";
            }
            else cur+=i;
        }
        for(auto& i:v){
            ans+='/'+i;
        }
        return ans==""?"/":ans;
    }
};