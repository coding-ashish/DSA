class Solution {
public:
    int smallestNumber(int n, int t) {
        int l = n;
        int up = n/10;
        up = (up+1)*10;
        
        while(true){
            if(prod(l)%t==0) return l;
            l++;
        }
        return up;
    }

    int prod(int l){
        int ans = 1;
        while(l){
            ans*=l%10;
            l=l/10;
        }
        return ans;
    }
};