#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstdlib>
using namespace std;
struct _d { int y, x; };
int main() {
	freopen("input.txt", "r", stdin);
	char b[10001];
	vector<_d> one, three;
	int i, j, M, ans = 0, cur, sum, used = 0;
	while (~scanf("%d\n", &M)) {
		one.clear();
		three.clear();
		for (i = 0; i < M; i++) {
			scanf("%s", b);
			for (j = 0; j < M; j++) {
				if (b[j] == '1') one.push_back(_d{ i,j });
				else if (b[j] == '3') three.push_back(_d{ i,j });
			}
		}
		ans = 0;
		for (_d& o : one) {
			cur = 1e9;
			for (_d& t : three) {
				sum = abs(o.y - t.y) + abs(o.x - t.x);
				cur = min(cur, sum);
			}
			ans = max(ans, cur);
		}
		printf("%d\n", ans);
		used = 1;
	}
	
	return 0;
}