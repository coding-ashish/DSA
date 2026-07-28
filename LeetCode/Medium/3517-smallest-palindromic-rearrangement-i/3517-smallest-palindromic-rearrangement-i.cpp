class Solution {
public:
    string smallestPalindrome(string s) {
        if (s.size()==1 || s.size()== 2){
            return s;
        }

        int j = s.size()/2-1;
        int  i =0;
        sort(s.begin(), s.begin() + j + 1);

        if(s.size()%2){
            j = s.size()/2;
            i=j;
        }else{
            j = s.size()/2;
            i = j-1;
        }

        while(j<s.size()){
            s[j] = s[i];
            j++;
            i--;
        }
        return s;
    }
};