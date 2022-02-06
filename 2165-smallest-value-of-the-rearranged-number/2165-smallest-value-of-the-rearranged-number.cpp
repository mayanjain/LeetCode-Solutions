class Solution {
public:
    long long smallestNumber(long long num) {
        bool neg=0;
        if(num<0){
            neg=1;
            num=-num;
        }
        vector<int> v;
        while(num){
            v.push_back(num%10);
            num/=10;
        }
        sort(v.begin(),v.end());
        if(neg)reverse(v.begin(),v.end());
        else{
            int i=0;
            while(i<v.size() && v[i]==0)i++;
            if(i<v.size())swap(v[i],v[0]);
        }
        long long ans=0;
        for(auto& i:v){
            ans=ans*10+i;
        }
        if(neg)ans=-ans;
        return ans;
    }
};