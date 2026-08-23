class Solution:
    def areRotations(self, s, goal):
        # code here
        if len(s) != len(goal):
            return False

        s = s + s
        if s.find(goal) != -1:
            return True

        return False