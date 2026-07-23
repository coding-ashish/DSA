class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> mini_ans;
        // ans.push_back({});
        helper(0,ans,mini_ans,nums);
        return ans;
    }

    void helper(int i,vector<vector<int>> &ans, vector<int> &mini_ans, vector<int> &nums){
        if(i>=nums.size()){
            ans.push_back(mini_ans);
            return;
        }

        mini_ans.push_back(nums[i]);
        helper(i+1,ans,mini_ans,nums);
        mini_ans.pop_back();
        helper(i+1,ans,mini_ans,nums);
    }
};