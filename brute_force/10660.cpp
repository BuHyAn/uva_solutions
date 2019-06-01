#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<algorithm>
using namespace std;
struct _d { int y, x; } a[25];
int main() {
	freopen("input.txt", "r", stdin);
	int t, n, i, j,k, per[25], y, x, sum, dist, tdist, p,b[5][5], mini_dist;
	vector<int> ans(5), tmp(5);
	scanf("%d", &t);
	while (t--) {
		memset(b, 0, sizeof b);
		memset(per, 0, sizeof per);
		fill(ans.begin(), ans.end(), 10000);
		scanf("%d", &n);
		for (i = 0; i < n; i++) {
			scanf("%d%d", &y, &x);
			scanf("%d", &b[y][x]);
		}
		for (i = 0; i < 5; i++) per[24 - i] = 1;
		mini_dist = 1e9;
		do {
			for (p = i = 0; i < 25; i++) if (per[i]) {
				tmp[p] = i;
				p++;
			}
			sum = 0;
			for (i = 0; i < 5; i++) for (j = 0; j < 5; j++) if(b[i][j]) {
				dist = 1e9;
				for (k = 0; k < 5; k++) {
					y = tmp[k] / 5, x = tmp[k] % 5;
					tdist = b[i][j] * (abs(i - y) + abs(j - x));
					dist = min(dist, tdist);
				}
				sum += dist;
			}
			if (mini_dist > sum) {
				mini_dist = sum;
				ans = tmp;
			}
			else if (mini_dist == sum && ans > tmp)
				ans = tmp;
		} while (next_permutation(per, per + 25));
		for (i = 0; i < 5; i++) {
			printf("%d", ans[i]);
			if (i != 4) printf(" ");
		}
		if (t) puts("");
	}
	return 0;
}