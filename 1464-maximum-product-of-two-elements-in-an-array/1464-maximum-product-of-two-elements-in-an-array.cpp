class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx = INT_MIN;
        int s_mx = INT_MIN;

        for (int  i =0; i<nums.size(); i++){
            if(nums[i] > mx){
                s_mx = mx;
                mx = nums[i];
            }
            else if(nums[i]>s_mx){
                s_mx = nums[i];
            }
            
        }

        return (mx-1)*(s_mx-1);
    }
};