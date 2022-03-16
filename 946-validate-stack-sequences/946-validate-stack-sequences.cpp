class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        vector<int> cur;
        int n=pushed.size();
        int j=0;
        for(int i=0 ; i<n ; i++){
            cur.push_back(pushed[i]);
            while(cur.size() && cur.back()==popped[j]){
                cur.pop_back();
                j++;
            }
        }
        return !cur.size();
    }
};