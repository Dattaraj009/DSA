class Solution {
public:
    int numberOfSubstrings(string s) {
        int l = 0;
        int r = 0;
        int n = s.size();
        int cnt = 0;
        unordered_map<char,int> mpp{
            {'a' , 0},
            {'b' , 0},
            {'c' , 0}
        };
        while(r<n){
            mpp[s[r]]++;

            if(mpp['a'] >=1 && mpp['b'] >= 1 && mpp['c'] >= 1){
                while(l <= r && mpp['a'] >=1 && mpp['b'] >= 1 && mpp['c'] >= 1){
                     cnt += (n-r);
                     mpp[s[l]]--;
                     l++;
                }
            }

            r++;
        }
        return cnt;
    }
};