class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& s,vector<vector<int>>& dp){
        int n = s.size();
        int m = s[0].size();
        if(i==n-1 && j==m-1) return 1;
        if(i >= n || j >= m) return 0;

        if(dp[i][j] != -1) return dp[i][j];
        if(s[i][j]==1) return 0;
        int right = solve(i,j+1,s,dp);
        int down = solve(i+1,j,s,dp);

        return dp[i][j] = right+down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1 || obstacleGrid[n-1][m-1]==1) return 0;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(0,0,obstacleGrid,dp);
    }
};