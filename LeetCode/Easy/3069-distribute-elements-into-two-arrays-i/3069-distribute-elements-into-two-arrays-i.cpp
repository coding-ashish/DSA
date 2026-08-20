class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1;
        arr1.push_back(nums[0]);
        vector<int> arr2;
        arr2.push_back(nums[1]);

        int i = 2;

        while (i < nums.size()) {
            if (arr1.back() > arr2.back()) {
                arr1.push_back(nums[i]);
            } else {
                arr2.push_back(nums[i]);
            }
            i++;
        }

        i = 0;
        while (i < arr2.size()){
            arr1.push_back(arr2[i]);
            i++;
        }

        return arr1;
    }
};