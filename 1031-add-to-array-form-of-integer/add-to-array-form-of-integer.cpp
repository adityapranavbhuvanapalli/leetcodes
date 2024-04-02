class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int carry = k, n = num.size();

        for(int i=n-1; i>=0; i--) {
            num[i] += carry;
            carry = num[i] / 10;
            num[i] = num[i] % 10;
        }

        while(carry) {
            num.insert(num.begin(), carry % 10);
            carry /= 10;
        }

        return num;
    }
};