class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {

        const long long MOD = 1e9 + 7;

        int n = s.size();

        vector<long long> pref(n + 1, 0);
        vector<long long> sum(n + 1, 0);
        vector<int> cnt(n + 1, 0);
        vector<long long> pow10(n + 1, 1);

        // powers of 10
        for (int i = 1; i <= n; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        for (int i = 0; i < n; i++) {

            int d = s[i] - '0';

            sum[i + 1] = sum[i];
            cnt[i + 1] = cnt[i];
            pref[i + 1] = pref[i];

            if (d != 0) {
                sum[i + 1] += d;
                cnt[i + 1]++;
                pref[i + 1] = (pref[i] * 10 + d) % MOD;
            }
        }

        vector<int> ans;

        for (auto &q : queries) {

            int l = q[0];
            int r = q[1];

            long long digitSum = sum[r + 1] - sum[l];

            int k = cnt[r + 1] - cnt[l];

            long long number =
                (pref[r + 1] - pref[l] * pow10[k]) % MOD;

            number = (number + MOD) % MOD;

            ans.push_back((digitSum * number) % MOD);
        }

        return ans;
    }
};