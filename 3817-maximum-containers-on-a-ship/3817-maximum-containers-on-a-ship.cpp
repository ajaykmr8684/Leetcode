class Solution {
public:
    int maxContainers(int n, int w, int maxWeight) {
        int count = 0;

        int actualDecks = n*n;

        while(maxWeight - w >= 0 && actualDecks > 0) {
            maxWeight = maxWeight - w;
            actualDecks--;
        }

        cout << actualDecks;

        return n*n - actualDecks;
    }
};