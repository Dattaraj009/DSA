class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        c = {}
        maxi = 0
        r = 0
        l = 0
        n = len(s)
        while r<n:
            if s[r] not in c:
                c[s[r]] = 1
            else:
                c[s[r]] += 1
            
            while c[s[r]] > 1:
                c[s[l]] -= 1
                l += 1
            
            maxi = max(r-l+1, maxi)
            r += 1
        return maxi