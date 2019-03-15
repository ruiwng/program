#include <stdlib.h>

int coinChange(int* coins, int coinsSize, int amount) {
	int *a = (int*)malloc((amount + 1) * sizeof(int));
	a[0] = 0;
	for (int i = 1; i < amount + 1; ++i)
		a[i] = -1;
	for (int i = 0; i < coinsSize; ++i) {
		int x = coins[i];
		for (int j = 0; j < amount + 1; ++j) {
			if (a[j] != -1) {
				int y = a[j];
				int z = x;
				int c = 1;
				while (j <= amount - z) {
					if (a[j + z] == -1 || a[j + z] > a[j] + c)
						a[j + z] = a[j] + c;
					z += x;
					c += 1;
				}
			}

		}
	}
	int m = a[amount];
	free(a);
	return m;
}

int main() {
	int coins[] = {1, 3, 5};
	int m = coinChange(coins, 3, 0);
	return 0;
}