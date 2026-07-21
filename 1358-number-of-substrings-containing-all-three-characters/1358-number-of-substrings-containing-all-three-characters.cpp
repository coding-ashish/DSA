class Solution {
public:
    int numberOfSubstrings(string s) {
        int i = 0;
        int ans = 0;
        vector<int> hash(3,0);
        for(int j = 0; j < s.size(); j++){
            hash[s[j]-'a']++;
            while(hash[0]!=0 && hash[1]!=0 && hash[2]!=0){
                ans += s.size()-j;
                hash[s[i]-'a']--;
                i++;
                // j--;
            }
        }
        return ans;
    }
};