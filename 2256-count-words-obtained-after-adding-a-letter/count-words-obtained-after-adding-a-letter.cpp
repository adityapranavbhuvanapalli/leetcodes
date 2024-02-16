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

    bool search(int i, int n, string& word, TrieNode* cur, bool mismatch) {
        if(i >= n)
            return cur->wordEnd && mismatch;

        bool res = false;

        if(cur->child[word[i] - 'a'])
            res = search(i + 1, n, word, cur->child[word[i] - 'a'], mismatch);

        if(res)
            return true;

        if(mismatch)
            return false;

        return search(i + 1, n, word, cur, true);

    }

    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        int count = 0;
        root = new TrieNode();

        for(auto& word: startWords) {
            sort(word.begin(), word.end());
            insert(word);
        }

        for(auto& word: targetWords) {
            cout<<word<<": ";
            sort(word.begin(), word.end());
            if(search(0, word.size(), word, root, false)) {
                count++;
            }
            cout<<count<<endl;
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