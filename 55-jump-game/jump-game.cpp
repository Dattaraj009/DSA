class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farth = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(i> farth){
                return false;
            }

            farth = max(i+nums[i],farth);
        }

        return true;
    }
};