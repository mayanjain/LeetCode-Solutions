class Solution {
public:
    int maxArea(int h, int w, vector<int>& hz, vector<int>& vs) {
        long long ls=0,hmx=0,vmx=0;
        sort(hz.begin(),hz.end());
        sort(vs.begin(),vs.end());
        for(auto& i:hz){
            hmx=max(hmx,i-ls);
            ls=i;
        }
        hmx=max(hmx,h-ls);
        ls=0;
        for(auto& i:vs){
            vmx=max(vmx,i-ls);
            ls=i;
        }
        vmx=max(vmx,w-ls);
        return (vmx*hmx)%(1000000007);
    }
};