#include<cstdio>
int t, n, a[12], cnt[12], used[12], uu;
void back(int p, int s) {
	if (p == n) {
		if (s == t) {
			if (uu) puts("");
			uu = 1;
			int nxt = 0, c;
			for (int i = 0; i < n; i++) {
				c = used[i];
				if (!c) continue;
				while (c--) {
					if (nxt) printf("+");
					printf("%d", a[i]);
					nxt = 1;
				}
			}
		}
		return;
	}
	for (int i = cnt[p]; i >= 0; i--) {
		if (s + a[p] * i <= t) {
			used[p] = i;
			back(p + 1, s + a[p] * i);
			used[p] = 0;
		}
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	int u = 0, i, j, d;
	while (1) {
		scanf("%d%d", &t, &n);
		if (!t && !n) break;
		j = 0;
		for (i = 0; i < n; i++) {
			scanf("%d", &d);
			if (!j || a[j - 1] != d) {
				cnt[j] = 1;
				a[j] = d;
				j++;
			}
			else cnt[j-1] += 1;
		}
		n = j;
		u = 1;
		uu = 0;
		printf("Sums of %d:\n", t);
		back(0, 0);
		if (!uu) printf("NONE");
		puts("");
	}
	return 0;
} 