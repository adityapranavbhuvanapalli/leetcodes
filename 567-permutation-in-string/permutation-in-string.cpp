class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l = 0, r = 0, n1 = s1.size(), n2 = s2.size();
        vector<int> freq1(26, 0), freq2(26, 0);

        for(const auto& ch: s1) {
            freq1[ch - 'a']++;
        }

        while(r < n2) {
            while(r - l + 1 > n1) {
                freq2[s2[l] - 'a']--;
                l++;
            }

            freq2[s2[r] - 'a']++;
            r++;

            if(freq1 == freq2)
                return true;
        }

        return false;
    }
};