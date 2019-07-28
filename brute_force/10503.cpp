#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n, m, used[14];
pair<int, int> ms[14], s, e, cur;
bool back(int u, int p) {
	if (u == n)
		return p == e.first;
	for (int i = 0; i < m; i++) if(!used[i]) {
		if (ms[i].first == p) {
			used[i] = 1;
			if (back(u + 1, ms[i].second))
				return 1;
			used[i] = 0;
		}
		else if (ms[i].second == p) {
			used[i] = 1;
			if (back(u + 1, ms[i].first))
				return 1;
			used[i] = 0;
		}
	}
	return 0;
}
int main() {
	freopen("input.txt", "r", stdin);
	int i;
	while (1) {
		scanf("%d", &n);
		if (!n) break;
		scanf("%d%d%d%d%d", &m, &s.first, &s.second, &e.first, &e.second);
		for (i = 0; i < m; i++)
			scanf("%d%d", &ms[i].first, &ms[i].second);
		memset(used, 0, sizeof used);
		puts(back(0, s.second) ? "YES" : "NO");
	}
	return 0;
}