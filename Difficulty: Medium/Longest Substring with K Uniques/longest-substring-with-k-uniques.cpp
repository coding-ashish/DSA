class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int mx = -1;
        int i = 0;
        int diff = 0;
        vector<int> ch(26,0);
        for(int j = 0; j < s.size(); j++){
            if(ch[s[j]-'a'] == 0 ){
                diff++;
            }
            ch[s[j]-'a']++;
            while(diff>k){
                if(ch[s[i]-'a']==1){
                    diff--;
                }
                ch[s[i]-'a']--;
                i++;
            }
            
            if(diff==k){
                mx=max(j-i+1,mx);
            }
        }
        return mx;
    }
};