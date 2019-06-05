#include<iostream>
#include<string>
#include<set>
using namespace std;
char b[2][6][6];
set<string> s[2];
string t;
void back(int w, int p) {
	if (p == 5) {
		s[w].insert(t);
		return;
	}
	for (int i = 0; i<6; i++) {
		t.push_back(b[w][i][p]);
		back(w, p + 1);
		t.pop_back();
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	int T, K, i, j, can;
	scanf("%d", &T);
	while (T--) {
		scanf("%d\n", &K);
		for (i = 0; i<2; i++) {
			for (j = 0; j<6; j++) scanf("%s", b[i][j]);
			s[i].clear();
			back(i, 0);
		}
		can = 0;
		for (auto it = s[0].begin(); it != s[0].end(); it++) if (s[1].find(*it) != s[1].end()) {
			K--;
			if (!K) {
				can = 1;
				cout << *it << '\n';
				break;
			}
		}
		if (!can) puts("NO");
	}
	return 0;
}