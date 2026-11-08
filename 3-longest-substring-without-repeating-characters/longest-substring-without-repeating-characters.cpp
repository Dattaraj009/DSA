class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int> mpp;
        int n = s.size();
        int r = 0,l=0;
        int maxi = 0;
        while(r<n){
            mpp[s[r]]++;
            if(mpp[s[r]] > 1){
                while(mpp[s[r]] > 1) {
                    mpp[s[l]]--;
                    l++;
                }
            }

            maxi = max((r-l+1), maxi);
            r++;
        }

        return maxi;
    }
};