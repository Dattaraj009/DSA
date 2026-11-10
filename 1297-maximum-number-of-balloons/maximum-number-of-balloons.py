class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        
        store = {'b': 0, 
        'a': 0, 
        'l': 0, 
        'o': 0, 
        'n': 0, 
        }
        
        for ch in text:
            if ch in store:
                store[ch] += 1

        store['l'] //= 2
        store['o'] //= 2

        return min(store.values())
             