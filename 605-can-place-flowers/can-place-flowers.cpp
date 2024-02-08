class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int zeroes = 0, count = 0;
        flowerbed.insert(flowerbed.begin(), 0);
        flowerbed.push_back(0);

        for(const auto& bed: flowerbed) {
            if(bed == 0) {
                zeroes++;
                continue;
            } 

            count += (zeroes - 1) / 2;
            zeroes = 0;
        }

        if(zeroes)
            count += (zeroes - 1) / 2;
        return count >= n;
    }
};