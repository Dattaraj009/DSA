class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_map<char,int> mpp{
            {'a',1},
            {'e',1},
            {'i',1},
            {'o',1},
            {'u',1}
        };
        int l = 0,r=0;
        int n = s.size();
        int cnt = 0;
        int maxi = 0;
        while(r<n){
           if(mpp.find(s[r]) != mpp.end()){
            cnt++;
           }
           if((r-l+1) > k){
             while((r-l+1) > k){
                if(mpp.find(s[l]) != mpp.end()){
                   cnt--;
                }
             l++;
            }
           }
           
           maxi = max(cnt,maxi);
           r++;
        }
        return maxi;
    }
};