class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0,low=0,high=height.size()-1,leftmx=0,rightmx=0;
        while(low<=high){
            if(height[low]<height[high]){
                if(leftmx<height[low])leftmx=height[low];
                else ans+=leftmx-height[low];
                low++;
            }
            else{
                if(rightmx<height[high])rightmx=height[high];
                else ans+=rightmx-height[high];
                high--;
            }
        }
        return ans;
    }
};