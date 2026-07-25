class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> temp(n,0);
        int i=1,j=n-1;
        while(i<n && j>=0){
            temp[i] = nums[j];
            i += 2;
            j--;
        }
        i=0;
        while(i<n && j>=0){
            temp[i] = nums[j];
            i += 2;
            j--;
        }
        i=0;
        while(i<n){
            nums[i] = temp[i];
            i++;
        }
    }
};