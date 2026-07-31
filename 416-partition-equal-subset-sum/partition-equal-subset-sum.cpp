class Solution {
public:
    int solve(int ind,int t,vector<vector<int>>& dp,vector<int>& nums){
        if(t==0) return 1;
        if(t < 0) return 0;
        int n = nums.size();
        if(ind == n) return 0;
        if(dp[ind][t]!=-1) return dp[ind][t];
        int take = 0;
        if(t-nums[ind] >= 0){
          take = solve(ind+1,t-nums[ind],dp,nums);
        }
        int nottake = solve(ind+1,t,dp,nums);

        return dp[ind][t] = take || nottake;
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum %2!=0) return false;
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(sum/2+1,-1));
        solve(0,sum/2,dp,nums);
        if(dp[0][sum/2]==1) return true;
        return false;
    }
};