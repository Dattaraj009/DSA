class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // this que is only solved my prefix sum
        int n = nums.size();
        unordered_map<int,int> mpp;
        int cnt = 0;
        int sum = 0;
        mpp[0] = 1;
        for(int i=0;i<n;i++){
            sum += nums[i];
            if(mpp.find(sum-k) != mpp.end()){
                cnt += mpp[sum-k];
            }

            mpp[sum]++;
        }

        return cnt;
    }
};