class Solution {
public:
    int solve(vector<int>& nums,int n,int k){
        unordered_map<int,int> mpp;
        int l=0,r=0;
        int cnt = 0;
        while(r<n){
            mpp[nums[r]]++;
            while(l<=r && mpp.size()>k){
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0) mpp.erase(nums[l]);
                l++;
            }

            cnt += (r-l+1);
            r++;
        }

        return cnt;
    }
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map<int,int> mpp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        int k = mpp.size();

        return solve(nums,n,k)-solve(nums,n,k-1);
    }
};