#include<cstdio>
const int MAX_N = 1450;
using ll = long long;
int main() {
	freopen("input.txt", "r", stdin);
	int C, n, i, d, j, k, c[21];
	ll a[MAX_N], cur;
	scanf("%d", &C);
	while (C--) {
		scanf("%d", &i);
		for (j =0;j<=i;j++)
			scanf("%d", &c[j]);
		for (j = 0; j < MAX_N; j++) {
			a[j] = c[i];
			for (k = i-1; k >= 0; k--)
				a[j] = a[j] * j + c[k];
		}
		scanf("%d%d", &d, &k);
		cur = 0;
		k -= 1;
		for (j = 0; j < MAX_N; j++) {
			if (cur > k) 
				break;
			cur += ((ll)j + 1)*d;
		}
		printf("%lld\n", a[j]);
	}
	return 0;
}
