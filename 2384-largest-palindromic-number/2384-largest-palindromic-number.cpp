class Solution {
public:
    string largestPalindromic(string num) {
        char mid='.';
        string ans="";
        map<char,int> mp;
        for(auto& i:num)mp[i]++;
        for(auto& i:mp){
            if(i.second%2){
                if(mid=='.')mid=i.first;
                mid=max(mid,i.first);
            }
            i.second/=2;
            while(i.second--)ans+=i.first;
        }
        sort(ans.begin(),ans.end());
        if(!ans.size() || ans.back()=='0'){
            ans="";
            if(mid=='.')mid='0';
            ans+=mid;
        }
        else{
            string end=ans;
            reverse(ans.begin(),ans.end());
            if(mid!='.')ans+=mid;
            ans+=end;
        }
        return ans;
    } 
};