class Solution {
public:
    struct TrieNode {
        int prefixCount;
        TrieNode* child[26] = {nullptr};
        TrieNode(): prefixCount(0), child() {}
    };

    void insert(TrieNode* root, string& s) {
        TrieNode* cur = root;

        for(const auto& ch: s) {
            if(!cur->child[ch - 'a']) 
                cur->child[ch - 'a'] = new TrieNode();
            
            cur = cur->child[ch - 'a'];
            cur->prefixCount++;
        }
    }

    int findScore(TrieNode* root, string& s) {
        TrieNode* cur = root;
        int score = 0;
        for(const auto& ch: s) {
            cur = cur->child[ch - 'a'];
            score += cur->prefixCount;
        }

        return score;
    }

    vector<int> sumPrefixScores(vector<string>& words) {
        vector<int> res;
        TrieNode* root = new TrieNode();

        for(auto& word: words) {
            insert(root, word);
        }

        for(auto& word: words)
            res.push_back(findScore(root, word));

        return res;
    }
};

/*
abc - a(2), ab(2), abc(1)   = 5
ab  - a(2), ab(2)           = 4
bc  - b(2), bc(1)           = 3
b   - b(2)                  = 2    

            *
          .    .
         a(2)  b(2)
        .        .
       b(2)      c(1)
      .
     c(1)
*/