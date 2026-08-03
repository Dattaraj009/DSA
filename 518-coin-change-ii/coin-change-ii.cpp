class Solution {
public:
    int solve(int ind,int k,vector<int>& coins,vector<vector<int>>& dp){
        int n = coins.size();
        if(ind==n){
            if(k==0) return 1;
            return 0;
        }
        if(dp[ind][k]!=-1) return dp[ind][k];
        int take = 0;
        if(k-coins[ind]>=0){
            take = solve(ind,k-coins[ind],coins,dp);
        }
        int nottake = solve(ind+1,k,coins,dp);

        return dp[ind][k] = take+nottake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return solve(0,amount,coins,dp);
    }
};