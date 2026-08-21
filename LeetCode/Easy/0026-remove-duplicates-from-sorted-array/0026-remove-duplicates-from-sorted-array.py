class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if not nums:
            return 0
        
        # 'left' keeps track of the position for the next unique element
        left = 1 
    
        # 'right' scans through the array looking for new unique elements
        for right in range(1, len(nums)):
            if nums[right] != nums[right - 1]:
            # Found a new unique number! Overwrite the duplicate.
                nums[left] = nums[right]
                left += 1
            
        # 'left' will naturally be the length of the unique portion
        return left
