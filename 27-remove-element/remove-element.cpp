class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        vector<int> store(n,100);
        int i = 0;
        queue<int> q;
        int cnt = 0;
        for( i=0;i<n;i++){
            q.push(nums[i]);
            if(nums[i] != val)cnt++;
        }
        i=0;
       while(!q.empty()){
        if(q.front() != val){
            nums[i] = q.front();
            i++;
        }
        q.pop();
       }
      return cnt;
       
    }
};