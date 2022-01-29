class Solution {
public:
    int largestRectangleArea(vector<int>& ht) {
        stack<int> st;
        int ans=0;
        ht.push_back(0);
        for(int i=0 ; i<ht.size() ; i++){
            while(!st.empty() && ht[st.top()]>=ht[i]){
                int h=ht[st.top()];st.pop();
                int l=st.empty()?-1:st.top();
                ans=max(ans,(i-l-1)*h);
            }
            st.push(i);
        }
        return ans;
    }
};