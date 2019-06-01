#include<cstdio>
#include<algorithm>
using namespace std;
const int MAX_N = 1000;
int main() {
	freopen("input.txt", "r", stdin);
	int C, n, a[MAX_N] = {}, i, j, ans;
	scanf("%d", &C);
	while (C--) {
		scanf("%d", &n);
		ans = 0;
		for (i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			for (j = 0; j < i; j++)
				ans += a[j] <= a[i];
		}
		printf("%d\n", ans);
	}
	return 0;
}
