class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> mpp;
        int maxfreq = 0;
        int maxi = 0;
        int l=0,r=0,n = s.size();
        while(r<n){
            mpp[s[r]]++;
            maxfreq = max(mpp[s[r]], maxfreq);
            while((r-l+1)-maxfreq > k){
              mpp[s[l]]--;
              l++;
            }
            maxi = max((r-l+1),maxi);
            r++;
        }

        return maxi;
    }
};