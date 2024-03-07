class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int maxVal = 0;
        for(const auto& str: strs) {
            int n = str.size(), val = 0;
            bool found = false;
            for(int i=0; i<n; i++) {
                if(isalpha(str[i])) {
                    maxVal = max(maxVal, n);
                    found = true;
                    break;
                }

                val = val * 10 + (str[i] - '0');
            }

            if(!found)
                maxVal = max(maxVal, val);
        }

        return maxVal;
    }
};