class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        int cnt = 0;
        for(int l=1;l<=n;l++){
            for(int i=0;i+l-1<n;i++){
                int j = i+l-1;
                if(i==j){
                    dp[i][j] = true;
                }
                else if(i+1==j && s[i]==s[j]){
                    dp[i][j] = true;
                }
                else if(s[i]==s[j] && dp[i+1][j-1]){
                    dp[i][j] = true;
                }

                if(dp[i][j]==true) cnt++;
            }
        }

        return cnt;
    }
};