#include<cstdio>
const int MAX_N = 1000;
int main() {
	freopen("input.txt", "r", stdin);
	int k, p, a[MAX_N][2], i, x, y;
	while (~scanf("%d", &k)) {
		p = 0;
		x = y = 2 * k;
		while (y > k) {
			if (y*k % (y-k) == 0) {
				x = y * k / (y - k);
				a[p][0] = x, a[p][1] = y;
				p += 1;
			}
			y -= 1;
		}
		printf("%d\n", p);
		for (i = p-1; i >= 0; i--)
			printf("1/%d = 1/%d + 1/%d\n", k, a[i][0], a[i][1]);
	}
	return 0;
}
