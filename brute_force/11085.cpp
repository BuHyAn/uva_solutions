#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
int rp[10], r[10], d[20], rd[20];
int back(int p) {
	if (p == 8) return 0;
	int ret = 1e9;
	for (int i = 0; i<8; i++) if (!r[i] && !d[10 + (i - p)] && !rd[i + p]) {
		r[i] = d[10 + (i - p)] = rd[i + p] = 1;
		ret = min(ret, (rp[p] != i) + back(p + 1));
		r[i] = d[10 + (i - p)] = rd[i + p] = 0;
	}
	return ret;
}
int main() {
	freopen("input.txt", "r", stdin);
	int i,tc=1;
	while (~scanf("%d", &r[0])) {
		r[0] -= 1;
		for (i = 1; i<8; i++) {
			scanf("%d", &rp[i]);
			rp[i] -= 1;
		}
		printf("Case %d: %d\n", tc++, back(0));
	}
	return 0;
}