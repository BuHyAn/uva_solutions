#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
struct _d { vector<int> clist; int w; };
int main() {
	freopen("input.txt", "r", stdin);
	int n, m, k, i, j, l, tc =1, cnt, anss, w[20], per[20], m_applied[10], tot, p;
	vector<int> ansc, tmp;
	vector<_d> ms;
	while (1) {
		scanf("%d%d", &n, &k);
		if (!n && !k) break;
		for (i = 0; i < n; i++) scanf("%d", &w[i]);
		scanf("%d", &m);
		ms.clear();
		ms.resize(m);
		for (i = 0; i < m; i++) {
			_d& c = ms[i];
			scanf("%d", &cnt);
			c.clist.resize(cnt);
			for (j = 0; j < cnt; j++) {
				scanf("%d", &c.clist[j]);
				c.clist[j] -= 1;
			}
			scanf("%d", &c.w);
		}
		ansc.clear(), tmp.clear();
		ansc.resize(k), tmp.resize(k);
		anss = 0;
		memset(per, 0, sizeof per);
		for (i = 0; i < k; i++) per[n - 1 - i] = 1;
		do {
			memset(m_applied, 0, sizeof m_applied);
			tot = 0;
			for (p = i = 0; i < n; i++) if (per[i]) {
				tmp[p] = i;
				p++;
				tot += w[i];
				for(j=0;j<m;j++) for(l=0;l<ms[j].clist.size();l++)
					if (ms[j].clist[l] == i) {
						m_applied[j] += 1;
						break;
					}
			}
			for (i = 0; i < m; i++) if(m_applied[i] > 0)
				tot -= ms[i].w * (m_applied[i] - 1);
			if (anss < tot) {
				anss = tot;
				ansc = tmp;
			}
			else if (anss == tot && ansc > tmp)
				ansc = tmp;
		} while (next_permutation(per, per + n));

		printf("Case Number  %d\n", tc);
		printf("Number of Customers : %d\n", anss);
		printf("Locations recommended :");
		for (i = 0; i < k; i++)
			printf(" %d", ansc[i] + 1);
		puts("\n");
		tc++;
	}
	return 0;
}
