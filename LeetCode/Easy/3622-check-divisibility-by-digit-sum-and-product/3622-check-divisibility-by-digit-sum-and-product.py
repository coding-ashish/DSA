class Solution:
    def checkDivisibility(self, n: int) -> bool:
        sm = 0
        pr = 1
        num = n
        while num :
            sm+=num%10
            num//=10

        num = n
        while num :
            pr*=num%10
            num//=10
        
        if n % (sm + pr) :
            return False
        else :
            return True