class Solution {
public:
    int solve(int i,int j,vector<int>& nums,int n){
        unordered_map<int,int> mpp;
        for(int k=i;k<=j;k++){
            mpp[nums[k]]++;
        }
        return mpp.size()*mpp.size();
    }
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                cnt += solve(i,j,nums,n);
            }
        }
    
        return cnt;
    }
};