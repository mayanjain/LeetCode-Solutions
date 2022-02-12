class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(),wordList.end());
        queue<string> q;
        q.push(beginWord);
        int ans=0;
        while(q.size()){
            ans++;
            for(int i=q.size() ; i>0 ; i--){
                string cur=q.front();
                q.pop();
                if(cur==endWord)return ans;
                for(int j=0 ; j<cur.size() ; j++){
                    char c=cur[j];
                    for(char k='a' ; k<='z' ; k++){
                        cur[j]=k;
                        if(dict.count(cur)){
                            q.push(cur);
                            dict.erase(cur);
                        }
                    }
                    cur[j]=c;
                }
            }
        }
        return 0;
    }
};