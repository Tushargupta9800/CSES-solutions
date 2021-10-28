class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size(),m=obstacleGrid[0].size();
        int dp[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
        dp[i][j]=0;}}
        if(obstacleGrid[0][0]==1)
            return 0;
        
    for(int k=0;k<m;k++){
            if(!obstacleGrid[0][k])
                dp[0][k]=1;
           else
               break;
        }
        for(int k=1;k<n;k++){
            if(!obstacleGrid[k][0])
                dp[k][0]=1;
           else
               break;
        }
        
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(!obstacleGrid[i][j])
                 dp[i][j]=dp[i-1][j]+dp[i][j-1];
                else
                    dp[i][j]=0;
                
            }
        }
        return dp[n-1][m-1];
        
        
    }
};
