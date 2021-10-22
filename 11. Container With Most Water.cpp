class Solution {
public:
    int maxArea(vector<int>& height) {
        
      int maxx = 0;
      int res = 0;
      int i = 0;
      int j = height.size() - 1;
        
      while (i != j) {
        if (height[i] < height[j]) {
          res = height[i] * (j-i);
          i++;
        } 
        else {
          res = height[j] * (j-i);
          j--;
        }
        maxx = max(maxx, res);
      }
      return maxx;
        
    }
};
