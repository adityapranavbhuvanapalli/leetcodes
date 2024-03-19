class Solution {
public:
    int res = 0;

    struct TrieNode {
        bool end = false;
        unordered_map<int, TrieNode*> child;
    };

    void insert(TrieNode* root, vector<int>& comb) {
        TrieNode* cur = root;

        for(const auto& num: comb) {
            if(cur->child.count(num) == 0) 
                cur->child[num] = new TrieNode();
            
            cur = cur->child[num];
        }

        if(!cur->end)
            res++;
        cur->end = true;
    }

    int countDistinct(vector<int>& nums, int k, int p) {
        int n = nums.size(), count;
        TrieNode* root = new TrieNode();

        for(int i=0; i<n; i++) {
            vector<int> comb;
            count = 0;
            for(int j=i; j<n; j++) {
                if(nums[j] % p == 0)
                    count++;

                if(count > k)
                    break;

                comb.push_back(nums[j]);
                insert(root, comb);
            }
        }

        return res;
    }
};

/*
k = 2, p = 2

count = 5

2   3   3   2   2

2   3   3   2   2
2   3   3   2   2
i
                j
    i
                    j
        i
                    j
            i
                    j
                i
                    j
*/