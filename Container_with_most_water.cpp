class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0,n=height.size(),r=n-1,ans=0;
        while(l<r){
            ans=max(ans,(r-l)*min(height[l],height[r]));
            if(height[l]<height[r])l+=1;
            else r-=1;
        }
        return ans;
    }
};
