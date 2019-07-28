#include<cstdio>
#include<algorithm>
using namespace std;
int N, cnt, a[20], ans, as, sum, s;
void back(int p) {
	if (p == cnt) {
		if (ans < sum) {
			ans = sum;
			as = s;
		}
		return;
	}
	if (sum + a[p] <= N) {
		sum += a[p], s |= (1 << p);
		back(p + 1);
		sum -= a[p], s ^= (1 << p);
	}
	back(p + 1);
}
int main() {
	freopen("input.txt", "r", stdin);
	int i;
	while (~scanf("%d", &N)) {
		scanf("%d", &cnt);
		for (i = 0; i < cnt; i++) scanf("%d", &a[i]);
		ans = as = 0;
		back(0);
		for (i = 0; i < cnt; i++) if (as & (1 << i))
			printf("%d ", a[i]);
		printf("sum: %d\n", ans);
	}

	return 0;
}