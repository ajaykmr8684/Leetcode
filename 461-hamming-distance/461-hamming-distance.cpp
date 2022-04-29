class Solution {
public:
    int hammingDistance(int x, int y) {
        int count = 0;

	/*  x : 0001 | y : 0100  */

	while (x > 0 || y > 0) {

		int digit1 = x & 1;
		x = x >> 1;

		int digit2 = y & 1;
		y = y >> 1;

		if (digit1 != digit2) {
			count++;
		}

	}

	return count;
    }
};