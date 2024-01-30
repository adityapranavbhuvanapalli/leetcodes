class Solution {
public:
    int count = 0;
    int countArrangement(int n) {
        vector<int> perm(n);
        for(int i=0; i<n; i++)
            perm[i] = i + 1;

        backtrack(0, n, perm);
        return count;
    }

    void backtrack(int start, int n, vector<int>& perm) {
        for(int i=0; i<start; i++) {
            if(!(perm[i] % (i + 1) == 0) && !((i + 1) % perm[i] == 0))
                return;
        }

        if(start == n) {
            count++;
            return;
        }

        for(int i=start; i<n; i++) {
            swap(perm[i], perm[start]);
            backtrack(start+1, n, perm);
            swap(perm[i], perm[start]);
        }
    }
};