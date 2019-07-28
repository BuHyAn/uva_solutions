#include<cstdio>
int n, a[17], can[33], used[17];
void rec(int p) {
	int i;
	if (p == n + 1) {
		if (can[a[n] + a[1]]) {
			printf("1");
			for (i = 2; i <= n; i++) printf(" %d", a[i]);
			puts("");
		}
		return;
	}
	for (i = 2; i <= n; i++) if (!used[i] && can[a[p-1] + i]) {
		used[i] = 1;
		a[p] = i;
		rec(p + 1);
		used[i] = 0;
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	int tc = 1, i, j, u = 0;
	for (i = 2; i < 33; i++) {
		can[i] = 1;
		for (j = 2; j < i; j++) 
			can[i] &= (i % j) > 0;
	}
	while (~scanf("%d", &n)) {
		if (u) puts("");
		printf("Case %d:\n", tc++);
		a[1] = 1;
		rec(2);
		u = 1;
	}
	return 0;
} 