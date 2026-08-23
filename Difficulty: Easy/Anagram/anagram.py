class Solution:
    def areAnagrams(self, s1, s2):
        # code here
        mpp1 = {}
        mpp2 = {}

        if len(s1)!= len(s2) :
            return False

        for i in s1:
            if i in mpp1:
                mpp1[i] += 1
            else:
                mpp1[i] = 1

        for i in s2:
            if i in mpp2:
                mpp2[i] += 1
            else :
                mpp2[i] = 1
               
        i = 0        
        while i < len(s1) :
            if not (s1[i] in mpp2 and mpp1[s1[i]] == mpp2[s1[i]]) :
                return False
            i+=1
        
        return True