class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string str = to_string(num);
        int count = 0, n = str.size();

        for(int i=0; i<=n-k; i++) {
            int divisor = stoi(str.substr(i, k));
            if(divisor > 0 && num % divisor == 0)
                count++;
        }

        return count;
    }
};

/*
430043
012345
*/