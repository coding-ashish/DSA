#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
    // 1. Define what information each segment needs to hold
    struct Node {
        int size;
        int max_len;
        int pref_len;
        int suff_len;
        char pref_char;
        char suff_char;
    };

    vector<Node> tree;

    // 2. Helper function to combine a left and right segment
    Node mergeNodes(Node left, Node right) {
        Node res;
        res.size = left.size + right.size;
        res.pref_char = left.pref_char;
        res.suff_char = right.suff_char;

        // --- STEP A: Calculate the new max length ---
        res.max_len = max(left.max_len, right.max_len);
        
        // If the middle characters connect, check if they form a new longest string
        if (left.suff_char == right.pref_char) {
            int combined_len = left.suff_len + right.pref_len;
            res.max_len = max(res.max_len, combined_len);
        }

        // --- STEP B: Calculate the new prefix length ---
        res.pref_len = left.pref_len;
        
        // If the ENTIRE left side is one repeating character, it spills over into the right side
        if (left.pref_len == left.size && left.pref_char == right.pref_char) {
            res.pref_len = left.size + right.pref_len;
        }

        // --- STEP C: Calculate the new suffix length ---
        res.suff_len = right.suff_len;
        
        // If the ENTIRE right side is one repeating character, it spills backwards into the left side
        if (right.suff_len == right.size && right.suff_char == left.suff_char) {
            res.suff_len = right.size + left.suff_len;
        }

        return res;
    }

    // 3. Build the initial tree
    void buildTree(string &s, int node, int start, int end) {
        // Base case: We are at a single character
        if (start == end) {
            tree[node].size = 1;
            tree[node].max_len = 1;
            tree[node].pref_len = 1;
            tree[node].suff_len = 1;
            tree[node].pref_char = s[start];
            tree[node].suff_char = s[start];
            return;
        }
        
        int mid = start + (end - start) / 2;
        buildTree(s, 2 * node, start, mid);
        buildTree(s, 2 * node + 1, mid + 1, end);
        
        // Combine the left and right children
        tree[node] = mergeNodes(tree[2 * node], tree[2 * node + 1]);
    }

    // 4. Update a character in the tree
    void updateTree(int node, int start, int end, int index, char new_char) {
        // Base case: We found the exact character to update
        if (start == end) {
            tree[node].pref_char = new_char;
            tree[node].suff_char = new_char;
            // Note: size, max_len, pref_len, suff_len are all still 1, no need to change them
            return;
        }
        
        int mid = start + (end - start) / 2;
        
        // Go down the correct path (left or right)
        if (index <= mid) {
            updateTree(2 * node, start, mid, index, new_char);
        } else {
            updateTree(2 * node + 1, mid + 1, end, index, new_char);
        }
        
        // After updating the child, recalculate this parent node
        tree[node] = mergeNodes(tree[2 * node], tree[2 * node + 1]);
    }

public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.length();
        
        // A segment tree needs roughly 4 * N space
        tree.resize(4 * n); 
        
        // Build the tree for the original string
        buildTree(s, 1, 0, n - 1);
        
        vector<int> ans;
        int k = queryIndices.size();
        
        // Process each query
        for (int i = 0; i < k; i++) {
            int idx = queryIndices[i];
            char c = queryCharacters[i];
            
            updateTree(1, 0, n - 1, idx, c);
            
            // The root node (node 1) always represents the entire string, so its max_len is our answer
            ans.push_back(tree[1].max_len);
        }
        
        return ans;
    }
};