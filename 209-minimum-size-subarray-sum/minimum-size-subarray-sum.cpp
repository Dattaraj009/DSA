class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 0,r=0;
        int sum = 0,mini = INT_MAX;
        while(r<n){
          sum += nums[r];
          while(sum - nums[l] >= target && l < r){
             sum -= nums[l];
             l++;
          }
         if(sum >= target) mini = min(mini,(r-l+1));
          r++;
        }
        if(mini == INT_MAX) return 0;
        return mini;
    }
};