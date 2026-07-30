class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        int ind = 0;
        int size = 0;
        for(int l=0;l<n;l++){
           for(int i=0;i+l<n;i++){
            int j = i+l;
            if(i==j ){
               dp[i][j] = true;
               if(size < (j-i+1)) ind = i,size = j-i+1;
            }
            else if(i+1 == j && s[i]==s[j]){
               dp[i][j] = true;

               if(size <(j-i+1))ind = i,size = j-i+1;
            }
            else if( s[i]==s[j] && dp[i+1][j-1]==true){
               dp[i][j] = true;
               if(size < (j-i+1))ind = i,size = j-i+1;
            }
           }
        }

        return s.substr(ind,size);
    }
};