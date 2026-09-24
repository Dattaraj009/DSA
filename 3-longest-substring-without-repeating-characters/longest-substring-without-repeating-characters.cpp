class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int> mpp;
        int n = s.size();
        int l=0,r=0;
        int maxi = 0;
        while(r<n){
            mpp[s[r]]++;
            while(mpp[s[r]] > 1 && l<r){
                mpp[s[l]]--;
                if(mpp[s[l]] == 0) mpp.erase(s[l]);
                l++;
            }
            maxi = max(maxi,(r-l+1));
            r++;
        }
        return maxi;
    }
};