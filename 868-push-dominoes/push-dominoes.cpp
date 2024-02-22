class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        int r = -1, prev = -1, rFound = false;

        for(int i=0; i<n; i++) {
            if(dominoes[i] == '.')
                continue;

            if(dominoes[i] == 'R') {
                if(rFound) {
                    // Make all Rs if R is found before
                    for(int j=r+1; j<=i; j++)
                        dominoes[j] = 'R';
                }
                r = i;
                rFound = true;
                // cout<<i<<": "<<r<<endl;
                continue;
            }

            int l = i;
            if(r > prev) {
                while(r < l) {
                    dominoes[l] = 'L';
                    dominoes[r] = 'R';
                    l--, r++;
                }
            } else {
                while(l > prev) {
                    dominoes[l] = 'L';
                    l--;
                }    
            }
            prev = i;
            rFound = false;
        }

        if(r > prev) {
            while(r < n) {
                dominoes[r] = 'R';
                r++;
            }
        }

        return dominoes;                
    }
};

/*

*/