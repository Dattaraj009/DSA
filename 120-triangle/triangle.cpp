class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& triangle,vector<vector<int>>& dp){
       int n = triangle.size();
       int m = triangle[j].size();
       if(j>=m) return 1e9;
       if(i==n-1) return triangle[i][j];
       if(dp[i][j] != INT_MAX) return dp[i][j];

       int down = solve(i+1,j,triangle,dp)+triangle[i][j];
       int digonal = solve(i+1,j+1,triangle,dp)+triangle[i][j];

       return dp[i][j] = min(down,digonal);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int m = triangle[n-1].size();
        vector<vector<int>> dp(n,vector<int>(m,INT_MAX));
        return solve(0,0,triangle,dp);
    }
};