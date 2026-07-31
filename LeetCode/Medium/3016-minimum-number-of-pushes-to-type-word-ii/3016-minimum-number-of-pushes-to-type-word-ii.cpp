class Solution {
public:
    int minimumPushes(string word) {
        
        vector<int> freq(26,0);

        int cnt = 0;

        for(int i =0; i< word.size(); i++){
            freq[word[i]-'a']++;
        }
        sort(freq.begin(), freq.end(), greater<int>());

        for(int i = 0; i< freq.size(); i++){
            if(freq[i]==0) break;
            if(i<=7){
                cnt=cnt+freq[i];
            }else if(i>7 && i<=15){
                cnt=cnt+freq[i]*2;
            }else if(i>15 && i<= 23){
                cnt = cnt + freq[i]*3;
            }else{
                cnt = cnt + freq[i]*4;
            }
        }
        return cnt;

    }
};