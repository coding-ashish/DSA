class Solution:
    def maxProfit(self, arr):
        # code here
        buy = arr[0]
        sell = arr[0]
        profit = 0
        for i in range(1,len(arr)) :
            if arr[i] < buy:
                sell = arr[i]
                buy = arr[i]

            elif arr[i] > sell:
                sell = arr[i]
            profit = max(profit,sell-buy)

        return profit