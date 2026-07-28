class Solution {
public:
    int maxProduct(int n) {
        int mx =INT_MIN;
        int s_mx = INT_MIN;

        while(n!=0){
            if(n%10>=mx){
                s_mx = mx;
                mx = n%10;
                // n/10;
            }else if(n%10 > s_mx){
                s_mx = n%10;
            }
            n=n/10;
        }
        return mx*s_mx;
    }
};