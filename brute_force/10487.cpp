#include<cstdio>
#include<cstdlib>
const int MAX_N = 1000;
int main() {
	freopen("input.txt", "r", stdin);
	int n, a[MAX_N], m, i, j, cs, diff, tc = 1, d;
	while (1) {
		scanf("%d", &n);
		if (!n) break;
		for (i = 0; i < n; i++) scanf("%d", &a[i]);
		printf("Case %d:\n", tc);
		scanf("%d", &m);
		while (m--) {
			scanf("%d", &d);
			diff = 1e9;
			for (i = 0; i < n; i++) for (j = 0; j < i; j++) if (abs(a[i] + a[j] - d) < diff) {
				diff = abs(a[i] + a[j] - d);
				cs = a[i] + a[j];
			}
			printf("Closest sum to %d is %d.\n", d, cs);
		}
		tc += 1;
	}
	return 0;
}
