class Solution {
public:
    vector<int> root;

    int find(int i) {
        return root[i] = (root[i] == i ? i : find(root[i]));
    }

    void unite(int a, int b) {
        int findA = find(a), findB = find(b);

        if(findA != findB) {
            root[max(findA, findB)] = min(findA, findB);
        }
    }

    bool equationsPossible(vector<string>& equations) {
        root.resize(26);

        for(int i=0; i<26; i++)
            root[i] = i;
    
        for(const auto& equation: equations) {
            if(equation[1] == '=') {
                unite(equation[0] - 'a', equation[3] - 'a');
            }
        }

        for(const auto& equation: equations) {
            if(equation[1] == '!' && find(equation[0] - 'a') == find(equation[3] - 'a'))
                return false;
        }

        return true;
    }
};

/*
a==b
b!=a

a-b
a~b

a-b
b-c
c-a

 1
a-b


a!=b
c==d
f==e

b!=b

f->e

c->d

a==b
c==d
b==c

a!=b
b!=a

a - a
b - b
*/