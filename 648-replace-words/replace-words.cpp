class Solution {
public:
    struct TrieNode {
        bool wordEnd = false;
        TrieNode* children[26] = {nullptr};
    };

    void insert(TrieNode* root, string& word) {
        TrieNode* cur = root;

        for(const auto& ch: word) {
            if(cur->wordEnd)
                return;

            if(!cur->children[ch - 'a'])
                cur->children[ch - 'a'] = new TrieNode();
            
            cur = cur->children[ch - 'a'];
        }

        cur->wordEnd = true;
    }

    string findPrefix(TrieNode* root, string& word) {
        TrieNode* cur = root;
        string prefix = "";
        for(const auto& ch: word) {
            if(cur->wordEnd)
                break;

            if(!cur->children[ch - 'a'])
                return word;
            
            prefix += ch;
            cur = cur->children[ch - 'a'];
        }

        return prefix.empty() ? word : prefix;
    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        string word = "", res = "";
        TrieNode* root = new TrieNode();

        sentence += " ";

        for(auto& word: dictionary) {
            insert(root, word);
        }

        for(const auto& ch: sentence) {
            if(ch != ' ') {
                word += ch;
                continue;   
            }

            // Process
            res += " " + findPrefix(root, word);
            word = "";
        }

        return &res[1];
    }
};

/*
dict:
ca
cat
bat
rat

the cattle


        #
       .  .
      b    c
     .     . 
    a      a(T)
   .       .
  t(T)     t(T)
*/