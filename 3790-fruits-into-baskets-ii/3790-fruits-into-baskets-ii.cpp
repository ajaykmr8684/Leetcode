class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int notPlaced = 0;

        for(int i = 0; i < baskets.size(); ++i)
        {
            for(int j = 0; j < baskets.size(); ++j) {
                if(fruits[i] <= baskets[j] && baskets[j] != -1){
                    baskets[j] = -1;
                    notPlaced++;
                    break;
                } 
            }   
        }

        return baskets.size() - notPlaced;

    }
};