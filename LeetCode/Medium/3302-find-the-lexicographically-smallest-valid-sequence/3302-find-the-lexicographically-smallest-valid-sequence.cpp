class Solution {
public:
    vector<int> validSequence(string word1, string word2) {

    vector<int> SuffixChar(word1.size() + 1, 0);

    int matched = 0;
    int i = word1.size() - 1;
    int j = word2.size() - 1;

    // SuffixChar[i] = how many characters of the
    // remaining word2 suffix can be matched from word1[i...]
    while (i >= 0) {

        if (j >= 0 && word1[i] == word2[j]) {
            matched++;
            j--;
        }

        SuffixChar[i] = matched;
        i--;
    }

    i = 0;
    j = 0;

    vector<int> ans;
    bool power = true;

    while (i < word1.size() && j < word2.size()) {

        // Exact match
        if (word1[i] == word2[j]) {
            ans.push_back(i);
            i++;
            j++;
        }

        // Use the one allowed mismatch
        else if (power &&
                 SuffixChar[i + 1] >= word2.size() - j - 1) {

            ans.push_back(i);
            power = false;
            i++;
            j++;
        }

        // Skip current character of word1
        else {
            i++;
        }
    }

    if (ans.size() != word2.size())
        return {};

    return ans;
}
};