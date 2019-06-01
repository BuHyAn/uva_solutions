#include<cstdio>
#include<set>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAX_N = 100;
int main() {
	freopen("input.txt", "r", stdin);
	int f, r, i, j, fs[MAX_N], rs[MAX_N], used = 0;
	double ans;
	set<double> d;
	while (scanf("%d", &f)) {
		if (!f) break;
		if (used) puts("");
		d.clear();
		scanf("%d", &r);
		for (i = 0; i < f; i++) scanf("%d", &fs[i]);
		for (i = 0; i < r; i++) {
			scanf("%d", &rs[i]);
			for (j = 0; j < f; j++)
				d.insert((double)rs[i] / fs[j]);
		}
		ans = 0;
		auto it = d.begin();
		auto nxt = it;
		nxt++;
		while (nxt != d.end()) {
			ans = max(ans, *nxt / *it);
			it = nxt;
			nxt++;
		}
		printf("%.2lf", ans);
		used = 1;
	}
	return 0;
}
