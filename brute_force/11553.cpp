#include<cstdio>
#include<algorithm>
using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	int t, i, j, per[8], n, m[8][8], ans, sum;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (i = 0; i < n; i++) {
			per[i] = i;
			for (j = 0; j < n; j++)
				scanf("%d", &m[i][j]);
		}
		ans = 1e9;
		do {
			sum = 0;
			for (i = 0; i < n; i++)
				sum += m[per[i]][i];
			ans = min(ans, sum);
		} while (next_permutation(per, per + n));
		printf("%d\n", ans);
	}
	return 0;
}
