class Solution:
    def isPalindrome(self, x: int) -> bool:
        c = str(x)
        n = len(c) 
        l = 0
        r = n-1
        while l <= r:
            if c[l] != c[r]:
                return False
            l += 1
            r -= 1
        
        return True