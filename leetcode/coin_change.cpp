#include <stdlib.h>

int coinChange(int* coins, int coinsSize, int amount) {
	int *a = (int*)malloc((amount + 1) * sizeof(int));
	a[0] = 0;
	for (int i = 1; i < amount + 1; ++i)
		a[i] = -1;
	for (int j = 0; j <= amount; ++j) {
		for (int i = 0; i < coinsSize; ++i) {
			if (j - coins[i] >= 0 && a[j - coins[i]] != -1 && (a[j] == -1 || a[j] > a[j - coins[i]] + 1))
				a[j] = a[j - coins[i]] + 1;
		}
	}
	int m = a[amount];
	free(a);
	return m;
}

int main() {
	int coins[] = {1, 3, 5};
	int m = coinChange(coins, 3, 11);
	return 0;
}