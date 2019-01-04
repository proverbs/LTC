class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for (int i = 0; i < flowerbed.size(); i ++) {
            if (flowerbed[i] || (i - 1 >= 0 && flowerbed[i - 1]) || (i + 1 < flowerbed.size() && flowerbed[i + 1])) continue;
            else flowerbed[i] = 1, n --;
        }
        return n <= 0;
    }
};