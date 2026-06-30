class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        unordered_set<int> st;
        int maxi = 0;
        // int cnt = 0;
        for(auto x:nums){
            st.insert(x);
        }

        for(auto x:st){
            if(st.find(x-1)==st.end()){
                int cnt = 0;
                while(st.find(x+1)!=st.end()){
                    x = x+1;
                    cnt++;
                }
                maxi = max(cnt,maxi);
            }
        }
        // if()
        return maxi+1;
    }
};