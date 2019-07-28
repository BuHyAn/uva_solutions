#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int MAX_N = 100;
vector<int> adj[MAX_N], al, tl;
int used[MAX_N], n;
void back(int u) {
	if (u == n) {
		if (al.size() < tl.size())
			al = tl;
		return;
	}
	int can = 1;
	for (int& v : adj[u]) if (used[v]) {
		can = 0;
		break;
	}
	if (can) {
		used[u] = 1;
		tl.push_back(u);
		back(u + 1);
		used[u] = 0;
		tl.pop_back();
	}
	back(u + 1);
}
int main() {
	freopen("input.txt", "r", stdin);
	int m, t, u, v, i, f;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		for (i = 0; i<n; i++) adj[i].clear();
		while (m--) {
			scanf("%d%d", &u, &v);
			u--, v--;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		al.clear();
		back(0);
		printf("%d\n", (int)al.size());
		f = 0;
		for (int& a : al) {
			if (f) printf(" ");
			printf("%d", a + 1);
			f = 1;
		}
		puts("");
	}
	return 0;
}