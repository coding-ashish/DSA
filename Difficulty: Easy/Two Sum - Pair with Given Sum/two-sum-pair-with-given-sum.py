class Solution:
	def twoSum(self, arr, target):
		# code here
		mpp = {}
		
		for i in arr :
		    if target-i in mpp :
		        return True
		    mpp[i]=1
		return False