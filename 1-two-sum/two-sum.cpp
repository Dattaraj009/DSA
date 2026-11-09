class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int n = nums.size();
        unordered_map<int,int> mpp;
        // mpp[0] = 1;
        for(int i=0;i<n;i++){
            if(mpp.find(target-nums[i]) != mpp.end()){
                return {mpp[target-nums[i]],i};
            }
            mpp[nums[i]] = i;
         }
         return {-1,-1};
    }
};