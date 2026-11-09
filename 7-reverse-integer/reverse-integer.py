class Solution:
    def reverse(self, x: int) -> int:
        check = False

        if x < 0:
            check = True
            x = abs(x)
            
        c = str(x)
        store = ""
        n = len(c)
        for i in range(n-1,-1,-1):
                store += c[i]
        
        ans = int(store)
        if check == True:
            ans = -ans
        
        if ans < -(2**31) or ans > (2**31):
            return 0
        return int(ans)