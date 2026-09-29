class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        if(grid[0][0]==1 || grid[r-1][c-1]){
            return 0;
        }
        vector<vector<int>> dp(r,vector<int>(c,0));
        dp[0][0]=1;
        for(int row=0;row<r;row++){
            for(int col=0;col<c;col++){
                if(col>0 && grid[row][col]!=1){
                    dp[row][col]+=dp[row][col-1];
                }
                if(row>0 && grid[row][col]!=1){
                    dp[row][col]+=dp[row-1][col];
                }
            }
        }
        return dp[r-1][c-1];
    }
};