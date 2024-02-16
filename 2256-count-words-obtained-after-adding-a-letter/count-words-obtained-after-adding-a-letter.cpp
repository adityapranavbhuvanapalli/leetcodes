class Solution {
public:
    struct TrieNode {
        bool wordEnd;
        vector<TrieNode*> child;
        TrieNode(): wordEnd(false), child(vector<TrieNode*>(26, nullptr)) {}
    };
    
    TrieNode* root = nullptr;

    void insert(string& word) {
        TrieNode* cur = root;

        for(const auto& ch: word) {
            if(!cur->child[ch - 'a'])
                cur->child[ch - 'a'] = new TrieNode();

            cur = cur->child[ch - 'a'];
        }

        cur->wordEnd = true;
    }
    
    // DFS search for string maximum 1 mismatch
    bool search(int i, int n, string& s, TrieNode* cur, bool ignored) {
        if(i >= n)
            return cur->wordEnd && ignored;

        bool pick = false, notpick = false;
        if(cur->child[s[i] - 'a'])
            pick = search(i + 1, n, s, cur->child[s[i] - 'a'], ignored);

        if(!ignored)  
            notpick = search(i + 1, n, s, cur, true);      

        return pick || notpick;
    }


    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        int count = 0;
        root = new TrieNode();

        for(auto& word: startWords) {
            sort(word.begin(), word.end());
            insert(word);
        }

        for(auto& word: targetWords) {
            sort(word.begin(), word.end());
            if(search(0, word.size(), word, root, false))
                count++;
        }

        return count;
    }
};

/*
ant act tack
tack act acti

ant

ant

actk
*/