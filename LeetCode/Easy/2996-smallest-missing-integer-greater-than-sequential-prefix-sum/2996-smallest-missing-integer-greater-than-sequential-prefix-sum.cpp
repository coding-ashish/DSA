#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int missingInteger(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        // 1. Calculate the sum of the longest sequential prefix
        int prefix_sum = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1] + 1) {
                prefix_sum += nums[i];
            } else {
                break; // Break as soon as the sequence is no longer sequential
            }
        }
        
        // 2. Load the array into an unordered_set for O(1) lookups
        unordered_set<int> present_nums(nums.begin(), nums.end());
        
        // 3. Find the smallest missing integer greater than or equal to the prefix sum
        int ans = prefix_sum;
        while (present_nums.count(ans)) {
            ans++;
        }
        
        return ans;
    }
};
