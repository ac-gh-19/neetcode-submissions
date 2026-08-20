class Solution { 
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        bool leftEmpty;
        bool rightEmpty;
        for (int i = 0; i < flowerbed.size(); ++i) {
            leftEmpty = (i == 0 ? true : flowerbed[i - 1] == 0);
            rightEmpty = (i == flowerbed.size() - 1 ? true : flowerbed[i + 1] == 0);
            if (leftEmpty && rightEmpty) {
                if (flowerbed[i] == 0) {
                    flowerbed[i] = 1;
                    n--;
                }
            }
        }
        
        return n <= 0;
    }
};