#include<cstdio>
#include<algorithm>
using namespace std;
const int MAX_N = 1000;
int main() {
	freopen("input.txt", "r", stdin);
	int C, n, a[MAX_N] = {}, i, ans;
	scanf("%d", &C);
	while (C--) {
		scanf("%d", &n);
		ans = 0;
		for (i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			if (i)
				ans += upper_bound(a, a + i, a[i]) - a;
			sort(a, a + i + 1);
		}
		printf("%d\n", ans);
	}
	return 0;
}
