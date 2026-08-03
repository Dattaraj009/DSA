class Solution {
public:
    int solve(int ind,int k,vector<int>& coins,vector<vector<int>>& dp){
        int n = coins.size();
        if(k==0) return 0;
        if(ind==n){
            return 1e9;
        }
        if(dp[ind][k] != -1) return dp[ind][k];
        int take = 1e9;
        if(k >= coins[ind]){
            take = solve(ind,k-coins[ind],coins,dp)+1;
        }
        int nottake = solve(ind+1,k,coins,dp);

        return dp[ind][k] = min(take,nottake);

    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans = solve(0,amount,coins,dp);
        if(ans==1e9) return -1;
        return ans;
    }
};