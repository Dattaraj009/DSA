class Solution {
public:
    
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        long long maxi = 0;
        int n = nums.size();
        int l=0,r=0;
        long long total = 0;
        while(r<n){
            
            if((r-l+1) > k){
                
              while((r-l+1) > k){
                mpp[nums[l]]--;
                total -= nums[l];
                if(mpp[nums[l]]==0) mpp.erase(nums[l]);
                l++;
              }
            }
            if(mpp.find(nums[r])==mpp.end()){
              total += nums[r];
              mpp[nums[r]]++;
            }
            else{
               while(mpp[nums[r]]!=0 && l<r){
                 mpp[nums[l]]--;
                 total -= nums[l];
                 l++;
                 
               }
               mpp[nums[r]]++;
               total += nums[r];
            }
            if((r-l+1) == k){
                maxi = max(total,maxi);
            }
            r++;
        }

        return maxi;
    }
};