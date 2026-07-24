class Solution {
public:
    string minWindow(string s, string t) {

        vector<int> freq(256, 0);

        for(char ch : t)
            freq[ch]++;

        int count = t.size();
        int i = 0;

        int start = 0;
        int len = INT_MAX;

        for(int j = 0; j < s.size(); j++) {

            if(freq[s[j]] > 0)
                count--;

            freq[s[j]]--;

            while(count == 0) {

                if(j - i + 1 < len) {
                    len = j - i + 1;
                    start = i;
                }

                freq[s[i]]++;

                if(freq[s[i]] > 0)
                    count++;

                i++;
            }
        }

        if(len == INT_MAX)
            return "";

        return s.substr(start, len);
    }
};