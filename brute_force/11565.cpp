#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	int N,A,B,C,i,j,k,can, x, y, z;
	vector<int> divi;
	scanf("%d", &N);
	while (N--) {
		scanf("%d%d%d", &A, &B, &C);
		divi.clear();
		for (i = 1; i <= B; i++) if(B%i == 0) {
			divi.push_back(i);
			divi.push_back(-i);
		}
		sort(divi.begin(), divi.end());
		can = 0;
		for (i = 0; !can && i < (int)divi.size(); i++) {
			x = divi[i];
			for (j = i+1; !can && j < (int)divi.size(); j++) {
				y = divi[j];
				if (B % (x*y) == 0) {
					z = B / (x*y);
					if (z <= y) continue;
					can |= x + y + z == A && x * x + y * y + z * z == C;
				}
			}
		}
		if (can) printf("%d %d %d\n", x, y, z);
		else puts("No solution.");
	}
	return 0;
}