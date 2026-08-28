class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = 0;
        int l = 0,r=0;
        int n = nums.size();
        int zero = 0;
        while(r<n){
           if(nums[r]==0) zero++;

           while(l<=r && zero > 1){
            if(nums[l]==0) zero--;

            l++;
           }

           maxi = max(maxi,(r-l));
           r++;
        }

        return maxi;
    }
};