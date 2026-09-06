class Solution {
public:
    int solve(int ind,int n,vector<int>& dp){
        if(ind==n) return 1;
        if(dp[ind] != -1) return dp[ind];
        int stepone = solve(ind+1,n,dp);
        int steptwo = 0;
        if(ind+2<=n) steptwo = solve(ind+2,n,dp);

        return dp[ind] = stepone+steptwo;

    }
    int climbStairs(int n) {
        vector<int> dp(n,-1);
        return solve(0,n,dp);
    }
};