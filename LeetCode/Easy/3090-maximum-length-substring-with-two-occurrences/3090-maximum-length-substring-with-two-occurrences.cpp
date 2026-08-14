class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<int,int> mpp;
        int i = 0;
        int j = 0;

        int mx = INT_MIN;

        while(j<s.size()){
            mpp[s[j]]++;
            while(mpp[s[j]]>2){
                mx = max(mx,j-i);
                mpp[s[i]]--;
                i++;
            }

            j++;
        }
        mx = max(mx,j-i);
        return mx;
    }
};