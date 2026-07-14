class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mpp;
        int n = s.size();
        int r=0,l=0;
        int maxi = 0;
        while(r<n){
            if(mpp.find(s[r]) != mpp.end()){
                while(mpp.find(s[r]) != mpp.end() && l<r){
                    mpp[s[l]]--;
                    if(mpp[s[l]]==0)mpp.erase(s[l]);
                    l++;
                }
            }
            mpp[s[r]]++;
            maxi = max((r-l+1),maxi);
            r++;
        }
        return maxi;
    }
};