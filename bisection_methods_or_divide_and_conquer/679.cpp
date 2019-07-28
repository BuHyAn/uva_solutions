#include<cstdio>
int main() {
	freopen("input.txt", "r", stdin);
	int D, I, u, L, l;
	scanf("%d", &l);
	while (l--) {
		scanf("%d%d", &D, &I);
		if (D == -1) break;
		L = 1 << (D - 1);
		u = 1;
		while (D - 1) {
			u = 2 * u + !(I % 2);
			I = I / 2 + (I % 2);
			D--;
			//printf("%d %d\n", u, I);
		}
		printf("%d\n", u);
	}
	return 0;
}