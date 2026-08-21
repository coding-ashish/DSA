# import math
class Solution:
    def majorityElement(self, arr):
        #code here
        count = 0
        element = -1
        for i in arr :
            if count == 0:
                element = i
                count+=1
            elif i == element:
                count+=1
            else :
                count-=1
        
        
        # check if the stored element is the majority element
        count = 0
        for i in arr :
            if i == element:
                count+=1
                
        if count > math.floor(len(arr)/2):
            return element
        return -1