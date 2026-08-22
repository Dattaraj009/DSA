class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp){
        int n = grid.size();
        int m = grid[0].size();
        if(i==n-1 && j==m-1) return grid[n-1][m-1];
        if(i>=n || j>= m) return 1e9;
        if(dp[i][j] != -1) return dp[i][j];

        int right = solve(i,j+1,grid,dp)+grid[i][j];
        int down = solve(i+1,j,grid,dp)+grid[i][j];
        return dp[i][j] = min(right,down);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(0,0,grid,dp);
    }
};