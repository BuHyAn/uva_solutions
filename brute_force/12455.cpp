#include<cstdio>
#include<cstring>
int main() {
	freopen("input.txt", "r", stdin);
	int t, n, p, i, j, R, bar, can[1001];
	scanf("%d", &t);
	while (t--) {
		memset(can, 0, sizeof can);
		can[0] = 1;
		R = 0;
		scanf("%d%d", &n, &p);
		for (i = 0; i < p; i++) {
			scanf("%d", &bar);
			for (j = R; j >= 0; j--) if (can[j] && j + bar <= n)
				can[j + bar] = 1;
			R += bar;
			R = R < n ? R : n;
		}
		puts(can[n] ? "YES" : "NO");
	}
	return 0;
}
