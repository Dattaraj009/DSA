class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        // cout<<6 % 18;
        for(int i=0;i<n;i++){
            int check = i+1;
            if(n % check == 0){
                int val = nums[i]*nums[i];
                sum += val;
            }
        }

        return sum;
    }
};